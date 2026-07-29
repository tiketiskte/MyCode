import { formatAmount } from '@/utils/format';
import { formatShortDayLabel } from '@/utils/date';
import type { MonthlyStats } from '@/types/stats';

interface StatCardProps {
  stats: MonthlyStats;
}

export function StatCard({ stats }: StatCardProps) {
  const title = stats.selectedDate
    ? `${formatShortDayLabel(stats.selectedDate)} 统计`
    : `${stats.month}月 统计`;

  return (
    <section className="-mt-2 rounded-2xl bg-white p-5 shadow-card">
      <p className="mb-4 text-sm font-medium text-text-secondary">{title}</p>
      <div className="grid grid-cols-3 gap-3">
        <div className="rounded-2xl bg-income/10 px-3 py-4 text-center">
          <p className="text-xs text-text-secondary">收入</p>
          <p className="mt-2 text-lg font-bold text-income">¥{formatAmount(stats.income)}</p>
        </div>
        <div className="rounded-2xl bg-expense/10 px-3 py-4 text-center">
          <p className="text-xs text-text-secondary">支出</p>
          <p className="mt-2 text-lg font-bold text-expense">¥{formatAmount(stats.expense)}</p>
        </div>
        <div className="rounded-2xl bg-primary/10 px-3 py-4 text-center">
          <p className="text-xs text-text-secondary">结余</p>
          <p className="mt-2 text-lg font-bold text-primary">¥{formatAmount(stats.balance)}</p>
        </div>
      </div>
    </section>
  );
}
