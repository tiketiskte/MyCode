export function normalizeAmount(value: number): number {
  return Math.round(value * 100) / 100;
}

export function formatAmount(amount: number): string {
  return amount.toLocaleString('zh-CN', {
    minimumFractionDigits: 2,
    maximumFractionDigits: 2,
  });
}

export function formatSignedAmount(type: 'income' | 'expense', amount: number): string {
  const prefix = type === 'income' ? '+' : '-';
  return `${prefix}¥${formatAmount(amount)}`;
}

export function sumAmounts(amounts: number[]): number {
  const totalCents = amounts.reduce((sum, amount) => sum + Math.round(amount * 100), 0);
  return totalCents / 100;
}
