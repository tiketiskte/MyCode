import { useEffect, useRef, useState } from "react";
import * as echarts from "echarts";
import api from "@/services/api";
import { useAuthStore } from "@/stores/authStore";
import { useNavigate } from "react-router-dom";

interface User {
  id: number;
  username: string;
  profile: { display_name: string };
  is_superuser: boolean;
}

interface CategoryStat {
  category: string;
  amount: number;
  count: number;
}

interface MonthlyTrend {
  month: string;
  income: number;
  expense: number;
  count: number;
}

interface AdminRecord {
  id: string;
  type: "income" | "expense";
  amount_yuan: number;
  note: string;
  category: string | null;
  date: string;
  user: string;
}

export function AdminDashboard() {
  const navigate = useNavigate();
  const user = useAuthStore((s) => s.user);
  const pieRef = useRef<HTMLDivElement>(null);
  const barRef = useRef<HTMLDivElement>(null);
  const [users, setUsers] = useState<User[]>([]);
  const [selectedUser, setSelectedUser] = useState("");
  const [records, setRecords] = useState<AdminRecord[]>([]);
  const [expenseData, setExpenseData] = useState<CategoryStat[]>([]);
  const [incomeData, setIncomeData] = useState<CategoryStat[]>([]);
  const [monthlyData, setMonthlyData] = useState<MonthlyTrend[]>([]);
  const [loading, setLoading] = useState(true);
  const [year, setYear] = useState(String(new Date().getFullYear()));
  const [month, setMonth] = useState("");

  // 如果没有权限，跳转
  useEffect(() => {
    if (user && !user.is_superuser) {
      navigate("/");
    }
  }, [user, navigate]);

  // 加载用户列表
  useEffect(() => {
    api.get("/admin/users/").then((r) => setUsers(r.data));
  }, []);

  // 加载数据
  const loadData = async () => {
    setLoading(true);
    const params: Record<string, string> = {};
    if (selectedUser) params.user_id = selectedUser;
    if (year) params.year = year;
    if (month) params.month = month;

    try {
      const [recordsRes, catRes, monthlyRes] = await Promise.all([
        api.get("/admin/records/", { params }),
        api.get("/admin/stats/category/", { params }),
        api.get("/admin/stats/monthly/", { params: { ...(year ? { year } : {}), ...(selectedUser ? { user_id: selectedUser } : {}) } }),
      ]);
      setRecords(recordsRes.data);
      setExpenseData(catRes.data.expense);
      setIncomeData(catRes.data.income);
      setMonthlyData(monthlyRes.data);
    } catch (e) {
      console.error("Failed to load admin data", e);
    }
    setLoading(false);
  };

  useEffect(() => { loadData(); }, [selectedUser, year, month]);

  // 绘制饼图
  useEffect(() => {
    if (!pieRef.current || expenseData.length === 0) return;
    const chart = echarts.init(pieRef.current);
    const colors = ["#FA5151", "#07C160", "#5865F2", "#FF9800", "#9C27B0", "#00BCD4", "#FF5722", "#795548"];
    chart.setOption({
      title: { text: "支出分类占比", left: "center", textStyle: { fontSize: 14 } },
      tooltip: { trigger: "item", formatter: "{b}: ¥{c} ({d}%)" },
      series: [{
        type: "pie",
        radius: ["30%", "60%"],
        center: ["50%", "55%"],
        data: expenseData.map((d, i) => ({
          name: d.category,
          value: d.amount,
          itemStyle: { color: colors[i % colors.length] },
        })),
        label: { formatter: "{b}\n¥{c}" },
        emphasis: {
          label: { show: true, fontSize: 14, fontWeight: "bold" },
        },
      }],
    });
    const handleResize = () => chart.resize();
    window.addEventListener("resize", handleResize);
    return () => {
      window.removeEventListener("resize", handleResize);
      chart.dispose();
    };
  }, [expenseData]);

  // 绘制柱状图
  useEffect(() => {
    if (!barRef.current || monthlyData.length === 0) return;
    const chart = echarts.init(barRef.current);
    chart.setOption({
      title: { text: "月度收支趋势", left: "center", textStyle: { fontSize: 14 } },
      tooltip: { trigger: "axis" },
      legend: { data: ["收入", "支出"], bottom: 0 },
      xAxis: {
        type: "category",
        data: monthlyData.map((d) => d.month),
      },
      yAxis: { type: "value", name: "金额(元)" },
      series: [
        {
          name: "收入",
          type: "bar",
          data: monthlyData.map((d) => d.income),
          itemStyle: { color: "#07C160" },
        },
        {
          name: "支出",
          type: "bar",
          data: monthlyData.map((d) => d.expense),
          itemStyle: { color: "#FA5151" },
        },
      ],
    });
    const handleResize = () => chart.resize();
    window.addEventListener("resize", handleResize);
    return () => {
      window.removeEventListener("resize", handleResize);
      chart.dispose();
    };
  }, [monthlyData]);

  const handleExport = () => {
    const params = new URLSearchParams();
    if (selectedUser) params.set("user_id", selectedUser);
    const token = localStorage.getItem("access_token");
    window.open(`http://localhost:8000/api/admin/export/?${params.toString()}`, "_blank");
    // 需要手动添加 Authorization header，用下载链接方式
    // 改用 fetch + blob
    fetch(`http://localhost:8000/api/admin/export/?${params.toString()}`, {
      headers: { Authorization: `Bearer ${token}` },
    })
      .then((r) => r.blob())
      .then((blob) => {
        const url = URL.createObjectURL(blob);
        const a = document.createElement("a");
        a.href = url;
        a.download = `records_export_${new Date().toISOString().slice(0, 10)}.csv`;
        a.click();
        URL.revokeObjectURL(url);
      });
  };

  if (!user?.is_superuser) return null;

  return (
    <div className="min-h-screen bg-surface pb-8">
      <header className="bg-gradient-primary px-4 pb-4 pt-6 text-white">
        <div className="flex items-center gap-3">
          <button onClick={() => navigate("/profile")} className="text-white/80">← 返回</button>
          <h1 className="text-xl font-bold">管理后台</h1>
        </div>
      </header>

      <main className="px-4 py-4 space-y-4">
        {/* 筛选器 */}
        <section className="rounded-2xl bg-white p-4 shadow-card">
          <div className="grid grid-cols-3 gap-3">
            <select
              value={selectedUser}
              onChange={(e) => setSelectedUser(e.target.value)}
              className="rounded-xl border border-gray-200 px-3 py-2 text-sm outline-none"
            >
              <option value="">所有用户</option>
              {users.map((u) => (
                <option key={u.id} value={u.id}>{u.profile?.display_name || u.username}</option>
              ))}
            </select>
            <input
              type="number"
              value={year}
              onChange={(e) => setYear(e.target.value)}
              placeholder="年份"
              className="rounded-xl border border-gray-200 px-3 py-2 text-sm outline-none"
            />
            <input
              type="number"
              value={month}
              onChange={(e) => setMonth(e.target.value)}
              placeholder="月份(可选)"
              min={1}
              max={12}
              className="rounded-xl border border-gray-200 px-3 py-2 text-sm outline-none"
            />
          </div>
        </section>

        {/* 图表 */}
        <div className="grid grid-cols-1 lg:grid-cols-2 gap-4">
          <section className="rounded-2xl bg-white p-4 shadow-card">
            <div ref={pieRef} style={{ height: 320 }} />
            {expenseData.length === 0 && !loading && (
              <p className="text-center text-sm text-text-secondary py-10">暂无支出数据</p>
            )}
          </section>
          <section className="rounded-2xl bg-white p-4 shadow-card">
            <div ref={barRef} style={{ height: 320 }} />
            {monthlyData.length === 0 && !loading && (
              <p className="text-center text-sm text-text-secondary py-10">暂无月度数据</p>
            )}
          </section>
        </div>

        {/* 导出按钮 */}
        <button
          onClick={handleExport}
          className="w-full rounded-2xl bg-primary py-3 text-sm font-semibold text-white transition active:bg-primary-dark"
        >
          导出 CSV
        </button>

        {/* 收入分类 */}
        {incomeData.length > 0 && (
          <section className="rounded-2xl bg-white p-4 shadow-card">
            <h3 className="mb-3 text-sm font-semibold text-text-secondary">收入分类</h3>
            <div className="space-y-2">
              {incomeData.map((d) => (
                <div key={d.category} className="flex justify-between items-center">
                  <span className="text-sm">{d.category}</span>
                  <span className="text-sm font-semibold text-income">+¥{d.amount.toFixed(2)}</span>
                </div>
              ))}
            </div>
          </section>
        )}

        {/* 记录列表 */}
        <section className="rounded-2xl bg-white p-4 shadow-card">
          <h3 className="mb-3 text-sm font-semibold text-text-secondary">
            记录列表 ({records.length})
          </h3>
          {records.length === 0 ? (
            <p className="text-center text-sm text-text-secondary py-4">暂无记录</p>
          ) : (
            <div className="space-y-2 max-h-96 overflow-y-auto">
              {records.map((r) => (
                <div key={r.id} className="flex justify-between items-center py-2 border-b border-gray-50 last:border-0">
                  <div className="min-w-0 flex-1">
                    <p className="text-sm truncate">{r.note || "未命名"}</p>
                    <p className="text-xs text-text-secondary">{r.date} · {r.user}</p>
                  </div>
                  <span className={`text-sm font-semibold shrink-0 ml-2 ${r.type === "income" ? "text-income" : "text-expense"}`}>
                    {r.type === "income" ? "+" : "-"}¥{r.amount_yuan.toFixed(2)}
                  </span>
                </div>
              ))}
            </div>
          )}
        </section>
      </main>
    </div>
  );
}
