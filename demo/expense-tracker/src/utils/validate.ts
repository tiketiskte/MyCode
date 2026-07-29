import { MAX_AMOUNT } from './constants';

export function validateAmount(value: string): string | null {
  if (!value.trim()) return '请输入有效金额';

  const num = Number(value);
  if (Number.isNaN(num) || num <= 0) return '金额必须大于 0';
  if (num > MAX_AMOUNT) return `金额不能超过 ${MAX_AMOUNT.toLocaleString('zh-CN')}`;
  if (!/^\d+(\.\d{1,2})?$/.test(value)) return '最多两位小数';

  return null;
}

export function truncateNote(note: string, maxLength = 100): string {
  return note.length > maxLength ? note.slice(0, maxLength) : note;
}
