import type { Record } from '@/types/record';
import type { DailyGroup, MonthlyStats } from '@/types/stats';
import { formatDayLabel } from '@/utils/date';
import { sumAmounts } from '@/utils/format';

function sumByType(records: Record[], type: Record['type']): number {
  const amounts = records.filter((record) => record.type === type).map((record) => record.amount);
  return sumAmounts(amounts);
}

export const statsService = {
  getMonthlyStats(records: Record[], year: number, month: number): MonthlyStats {
    const income = sumByType(records, 'income');
    const expense = sumByType(records, 'expense');

    return {
      year,
      month,
      income,
      expense,
      balance: sumAmounts([income, -expense]),
    };
  },

  groupByDay(records: Record[]): DailyGroup[] {
    const groups = new Map<string, Record[]>();

    for (const record of records) {
      const existing = groups.get(record.date) ?? [];
      existing.push(record);
      groups.set(record.date, existing);
    }

    return Array.from(groups.entries())
      .sort(([a], [b]) => b.localeCompare(a))
      .map(([date, dayRecords]) => ({
        date,
        dayLabel: formatDayLabel(date),
        records: dayRecords.sort((a, b) => b.time.localeCompare(a.time)),
        dayIncome: sumByType(dayRecords, 'income'),
        dayExpense: sumByType(dayRecords, 'expense'),
      }));
  },
};
