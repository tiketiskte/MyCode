import { useEffect, useRef, useState } from "react";
import { useNavigate, Link } from "react-router-dom";
import { useAuthStore } from "@/stores/authStore";
import { useRecordStore, useUIStore } from "@/stores";
import { formatAmount } from "@/utils/format";

export function ProfilePage() {
  const navigate = useNavigate();
  const { user, logout, updateProfile, updateAvatar } = useAuthStore();
  const { records, fetchRecords, isLoading } = useRecordStore();
  const { currentYear, currentMonth, showToast } = useUIStore();

  const [stats, setStats] = useState({ income: 0, expense: 0, count: 0 });
  const [editingName, setEditingName] = useState(false);
  const [nameInput, setNameInput] = useState("");
  const [saving, setSaving] = useState(false);
  const [avatarPreview, setAvatarPreview] = useState<string | null>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    fetchRecords(currentYear, currentMonth);
  }, [currentYear, currentMonth, fetchRecords]);

  useEffect(() => {
    const income = records.filter((r) => r.type === "income").reduce((s, r) => s + r.amount, 0);
    const expense = records.filter((r) => r.type === "expense").reduce((s, r) => s + r.amount, 0);
    setStats({ income, expense, count: records.length });
  }, [records]);

  const handleSaveName = async () => {
    if (!nameInput.trim() || nameInput === (user?.profile?.display_name || user?.username)) {
      setEditingName(false);
      return;
    }
    setSaving(true);
    try {
      await updateProfile({ display_name: nameInput.trim() });
      showToast("已更新显示名称");
      setEditingName(false);
    } catch {
      showToast("更新失败，请重试");
    }
    setSaving(false);
  };

  const handleAvatarChange = async (e: React.ChangeEvent<HTMLInputElement>) => {
    const file = e.target.files?.[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = (ev) => setAvatarPreview(ev.target?.result as string);
    reader.readAsDataURL(file);

    try {
      await updateAvatar(file);
      showToast("头像已更新");
    } catch {
      showToast("头像更新失败");
    }
  };

  const handleLogout = () => {
    logout();
    navigate("/login");
  };

  const displayName = user?.profile?.display_name || user?.username || "用户";
  const avatarUrl = avatarPreview || user?.profile?.avatar || null;

  return (
    <div className="min-h-screen bg-surface pb-24">
      {/* 头部 */}
      <header className="bg-gradient-primary px-4 pb-8 pt-6 text-white relative">
        <button onClick={() => navigate(-1)} className="absolute left-4 top-6 text-white/80 text-lg">
          ← 返回
        </button>
        <div className="text-center pt-4">
          {/* 头像 */}
          <div className="relative mx-auto mb-4 w-20 h-20">
            <button
              onClick={() => fileInputRef.current?.click()}
              className="w-full h-full rounded-full overflow-hidden border-2 border-white/30 hover:border-white/60 transition"
            >
              {avatarUrl ? (
                <img src={avatarUrl} alt="头像" className="w-full h-full object-cover" />
              ) : (
                <div className="w-full h-full bg-white/20 flex items-center justify-center text-3xl">
                  👤
                </div>
              )}
            </button>
            <button
              onClick={() => fileInputRef.current?.click()}
              className="absolute -bottom-1 -right-1 w-7 h-7 rounded-full bg-white shadow flex items-center justify-center text-xs text-gray-600"
            >
              📷
            </button>
            <input
              ref={fileInputRef}
              type="file"
              accept="image/*"
              onChange={handleAvatarChange}
              className="hidden"
            />
          </div>

          {editingName ? (
            <div className="flex items-center justify-center gap-2">
              <input
                type="text"
                value={nameInput}
                onChange={(e) => setNameInput(e.target.value)}
                className="rounded-lg border-0 px-3 py-1.5 text-center text-lg font-bold text-gray-800 outline-none"
                autoFocus
                onKeyDown={(e) => e.key === "Enter" && handleSaveName()}
              />
              <button onClick={handleSaveName} disabled={saving}
                className="rounded-lg bg-white/20 px-3 py-1.5 text-sm font-semibold text-white">
                {saving ? "保存中" : "保存"}
              </button>
              <button onClick={() => setEditingName(false)}
                className="rounded-lg bg-white/10 px-3 py-1.5 text-sm text-white/80">
                取消
              </button>
            </div>
          ) : (
            <div className="group inline-flex items-center gap-1">
              <h1 className="text-xl font-bold">{displayName}</h1>
              <button onClick={() => { setNameInput(displayName); setEditingName(true); }}
                className="text-sm text-white/60 hover:text-white transition">✏️</button>
            </div>
          )}

          <p className="mt-1 text-sm text-white/80">@{user?.username}</p>
          {user?.is_superuser && (
            <span className="mt-2 inline-block rounded-full bg-yellow-400 px-3 py-0.5 text-xs font-semibold text-amber-900">
              管理员
            </span>
          )}
        </div>
      </header>

      <main className="px-4 py-4 space-y-4">
        {/* 本月统计 */}
        <section className="rounded-2xl bg-white p-5 shadow-card">
          <h2 className="text-sm font-semibold text-text-secondary mb-3 text-center">本月统计</h2>
          {isLoading ? (
            <p className="text-sm text-text-secondary text-center py-4">加载中...</p>
          ) : (
            <div className="grid grid-cols-3 gap-4 text-center">
              <div>
                <p className="text-2xl font-bold text-income">+{formatAmount(stats.income)}</p>
                <p className="mt-1 text-xs text-text-secondary">收入</p>
              </div>
              <div>
                <p className="text-2xl font-bold text-expense">-{formatAmount(stats.expense)}</p>
                <p className="mt-1 text-xs text-text-secondary">支出</p>
              </div>
              <div>
                <p className="text-2xl font-bold text-primary">{formatAmount(stats.income - stats.expense)}</p>
                <p className="mt-1 text-xs text-text-secondary">结余</p>
              </div>
            </div>
          )}
          <p className="mt-3 text-center text-xs text-text-secondary">本月共 {stats.count} 条记录</p>
        </section>

        {/* 账号信息 */}
        <section className="rounded-2xl bg-white p-5 shadow-card space-y-3">
          <h2 className="text-sm font-semibold text-text-secondary">账号信息</h2>
          <div className="flex justify-between items-center">
            <span className="text-sm text-text-secondary">用户名</span>
            <span className="text-sm font-medium">{user?.username}</span>
          </div>
          <div className="flex justify-between items-center border-t border-gray-50 pt-3">
            <span className="text-sm text-text-secondary">显示名称</span>
            <div className="flex items-center gap-2">
              <span className="text-sm font-medium">{displayName}</span>
              <button onClick={() => { setNameInput(displayName); setEditingName(true); }}
                className="text-xs text-primary">编辑</button>
            </div>
          </div>
          <div className="flex justify-between items-center border-t border-gray-50 pt-3">
            <span className="text-sm text-text-secondary">角色</span>
            <span className="text-sm font-medium">{user?.is_superuser ? "管理员" : "普通用户"}</span>
          </div>
        </section>

        {/* 管理入口 */}
        {user?.is_superuser && (
          <Link to="/admin"
            className="flex items-center justify-between rounded-2xl bg-white p-5 shadow-card transition active:scale-[0.99]">
            <div className="flex items-center gap-3">
              <span className="text-2xl">📊</span>
              <div>
                <p className="font-semibold text-text-primary">管理后台</p>
                <p className="text-xs text-text-secondary">查看所有用户数据、统计图表、导出</p>
              </div>
            </div>
            <span className="text-text-secondary">→</span>
          </Link>
        )}

        {/* 退出 */}
        <button onClick={handleLogout}
          className="w-full rounded-2xl bg-white p-4 text-center text-sm font-medium text-expense shadow-card transition active:scale-[0.99]">
          退出登录
        </button>
      </main>
    </div>
  );
}
