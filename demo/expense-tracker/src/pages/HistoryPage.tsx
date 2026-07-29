import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { recordService } from '@/services';
import { useUIStore } from '@/stores';
import type { MonthSummary } from '@/types';
import { formatAmount } from '@/utils/format';

export function HistoryPage() {
  const navigate = useNavigate();
  const setMonth = useUIStore((state) => state.setMonth);
  const [summaries, setSummaries] = useState<MonthSummary[]>([]);
  const [isLoading, setIsLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    void recordService
      .getMonthSummaries()
      .then((data) => {
        setSummaries(data);
        setError(null);
      })
      .catch((reason: unknown) => {
        setError(reason instanceof Error ? reason.message : '加载历史账单失败');
      })
      .finally(() => {
        setIsLoading(false);
      });
  }, []);

  const handleSelectMonth = (summary: MonthSummary) => {
    setMonth(summary.year, summary.month);
    navigate('/');
  };

  return (
    <div className="min-h-screen pb-24">
      <header className="bg-gradient-primary px-4 pb-6 pt-6 text-white">
        <h1 className="text-2xl font-bold">历史账单</h1>
        <p className="mt-1 text-sm text-white/80">按月份回溯查看收支</p>
      </header>

      <main className="px-4 py-4">
        {isLoading ? (
          <p className="py-12 text-center text-sm text-text-secondary">加载中...</p>
        ) : error ? (
          <div className="rounded-2xl bg-white px-4 py-12 text-center shadow-card">
            <p className="text-base font-medium text-expense">加载失败</p>
            <p className="mt-2 text-sm text-text-secondary">{error}</p>
          </div>
        ) : summaries.length === 0 ? (
          <div className="rounded-2xl bg-white py-12 text-center shadow-card">
            <p className="text-base font-medium text-text-primary">还没有历史记录</p>
            <p className="mt-2 text-sm text-text-secondary">记第一笔账后这里会按月汇总</p>
          </div>
        ) : (
          <div className="space-y-3">
            {summaries.map((summary) => (
              <button
                key={summary.monthKey}
                type="button"
                onClick={() => handleSelectMonth(summary)}
                className="w-full rounded-2xl bg-white p-4 text-left shadow-card transition active:scale-[0.99]"
              >
                <div className="flex items-center justify-between">
                  <div>
                    <p className="text-lg font-bold text-text-primary">{summary.label}</p>
                    <p className="mt-1 text-xs text-text-secondary">共 {summary.count} 笔记录</p>
                  </div>
                  <div className="text-right">
                    <p className="text-sm font-semibold text-primary">
                      结余 ¥{formatAmount(summary.balance)}
                    </p>
                    <p className="mt-1 text-xs text-text-secondary">
                      收 {formatAmount(summary.income)} / 支 {formatAmount(summary.expense)}
                    </p>
                  </div>
                </div>
              </button>
            ))}
          </div>
        )}
      </main>
    </div>
  );
}
