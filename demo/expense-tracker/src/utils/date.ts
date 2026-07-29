import { format, parseISO } from 'date-fns';
import { zhCN } from 'date-fns/locale';

export function getTodayDateString(): string {
  return format(new Date(), 'yyyy-MM-dd');
}

export function getNowTimeString(): string {
  return format(new Date(), 'HH:mm');
}

export function getNowDateTime() {
  const now = new Date();
  return {
    date: format(now, 'yyyy-MM-dd'),
    time: format(now, 'HH:mm'),
    datetime: now,
  };
}

export function formatDayLabel(dateString: string): string {
  const date = parseISO(dateString);
  return format(date, 'M月d日 EEEE', { locale: zhCN });
}

export function formatShortDayLabel(dateString: string): string {
  if (dateString === getTodayDateString()) return '今天';
  const yesterday = new Date();
  yesterday.setDate(yesterday.getDate() - 1);
  if (dateString === format(yesterday, 'yyyy-MM-dd')) return '昨天';
  const date = parseISO(dateString);
  return format(date, 'M月d日', { locale: zhCN });
}

export function formatMonthLabel(year: number, month: number): string {
  return `${year}年${month}月`;
}

export function formatMonthKey(year: number, month: number): string {
  return `${year}-${String(month).padStart(2, '0')}`;
}

export function formatRecordDateTime(date: string, time: string): string {
  return `${formatShortDayLabel(date)} ${time}`;
}

export function formatLiveDateTime(date: Date): string {
  return format(date, 'M月d日 EEEE HH:mm:ss', { locale: zhCN });
}

export function getMonthDateRange(year: number, month: number) {
  const startDate = `${year}-${String(month).padStart(2, '0')}-01`;
  const lastDay = new Date(year, month, 0).getDate();
  const endDate = `${year}-${String(month).padStart(2, '0')}-${String(lastDay).padStart(2, '0')}`;
  return { startDate, endDate, daysInMonth: lastDay };
}

export function toDateString(year: number, month: number, day: number): string {
  return `${year}-${String(month).padStart(2, '0')}-${String(day).padStart(2, '0')}`;
}

export function isToday(dateString: string): boolean {
  return dateString === getTodayDateString();
}

export function isCurrentMonth(year: number, month: number): boolean {
  const now = new Date();
  return year === now.getFullYear() && month === now.getMonth() + 1;
}

export function shiftMonth(year: number, month: number, delta: number) {
  const date = new Date(year, month - 1 + delta, 1);
  return {
    year: date.getFullYear(),
    month: date.getMonth() + 1,
  };
}

export function isFutureMonth(year: number, month: number): boolean {
  const now = new Date();
  const currentYear = now.getFullYear();
  const currentMonth = now.getMonth() + 1;
  return year > currentYear || (year === currentYear && month > currentMonth);
}

export function isFutureDate(dateString: string): boolean {
  return dateString > getTodayDateString();
}

export function getMonthOptions(yearsBack = 5) {
  const now = new Date();
  const options: { year: number; month: number; label: string }[] = [];
  for (let i = 0; i <= yearsBack * 12; i++) {
    const date = new Date(now.getFullYear(), now.getMonth() - i, 1);
    const year = date.getFullYear();
    const month = date.getMonth() + 1;
    options.push({ year, month, label: formatMonthLabel(year, month) });
  }
  return options;
}
