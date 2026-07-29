import type { Record } from './record';

export interface MonthlyStats {
  year: number;
  month: number;
  income: number;
  expense: number;
  balance: number;
  selectedDate?: string | null;
}

export interface DailyGroup {
  date: string;
  dayLabel: string;
  records: Record[];
  dayIncome: number;
  dayExpense: number;
}

export interface MonthSummary {
  year: number;
  month: number;
  monthKey: string;
  label: string;
  income: number;
  expense: number;
  balance: number;
  count: number;
}
