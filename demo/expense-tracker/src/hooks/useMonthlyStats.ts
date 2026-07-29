import { useMemo } from 'react';
import type { Record } from '@/types/record';

export function useMonthlyStats(
  records: Record[],
  currentYear: number,
  currentMonth: number,
  selectedDate: string | null,
) {
  return useMemo(() => {
    const incomeCents = records
      .filter((record) => record.type === 'income')
      .reduce((sum, record) => sum + Math.round(record.amount * 100), 0);
    const expenseCents = records
      .filter((record) => record.type === 'expense')
      .reduce((sum, record) => sum + Math.round(record.amount * 100), 0);

    return {
      year: currentYear,
      month: currentMonth,
      income: incomeCents / 100,
      expense: expenseCents / 100,
      balance: (incomeCents - expenseCents) / 100,
      selectedDate,
    };
  }, [records, currentYear, currentMonth, selectedDate]);
}
