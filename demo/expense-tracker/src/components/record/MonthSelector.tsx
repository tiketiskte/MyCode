import { useMemo, useState } from 'react';
import { formatMonthLabel } from '@/utils/date';

interface MonthSelectorProps {
  year: number;
  month: number;
  onSelect: (year: number, month: number) => void;
  onClose: () => void;
}

export function MonthSelector({ year, month, onSelect, onClose }: MonthSelectorProps) {
  const now = new Date();
  const currentYear = now.getFullYear();
  const currentMonth = now.getMonth() + 1;
  const years = useMemo(
    () => Array.from({ length: 6 }, (_, index) => currentYear - index),
    [currentYear],
  );
  const [selectedYear, setSelectedYear] = useState(year);
  const [selectedMonth, setSelectedMonth] = useState(month);

  const handleSelectYear = (nextYear: number) => {
    setSelectedYear(nextYear);
    if (nextYear === currentYear && selectedMonth > currentMonth) {
      setSelectedMonth(currentMonth);
    }
  };

  const handleConfirm = () => {
    onSelect(selectedYear, selectedMonth);
    onClose();
  };

  return (
    <div className="fixed inset-0 z-50 flex items-end justify-center bg-black/45 px-4 pb-safe">
      <div className="w-full max-w-app animate-slide-up rounded-t-3xl bg-white p-5 shadow-xl">
        <div className="mb-4 flex items-center justify-between">
          <h2 className="text-lg font-semibold">选择月份</h2>
          <button
            type="button"
            onClick={onClose}
            className="rounded-full px-3 py-1 text-sm text-text-secondary hover:bg-gray-100"
          >
            取消
          </button>
        </div>

        <div className="grid max-h-[22rem] grid-cols-[6.5rem_1fr] gap-3 overflow-hidden">
          <div className="space-y-1 overflow-y-auto rounded-2xl bg-gray-50 p-1">
            {years.map((item) => {
              const isActive = item === selectedYear;
              return (
                <button
                  key={item}
                  type="button"
                  onClick={() => handleSelectYear(item)}
                  className={`w-full rounded-xl px-3 py-3 text-sm font-semibold transition ${
                    isActive ? 'bg-white text-primary shadow-sm' : 'text-text-secondary'
                  }`}
                >
                  {item}年
                </button>
              );
            })}
          </div>

          <div>
            <p className="mb-2 text-sm font-medium text-text-secondary">
              {formatMonthLabel(selectedYear, selectedMonth)}
            </p>
            <div className="grid grid-cols-3 gap-2">
              {Array.from({ length: 12 }, (_, index) => index + 1).map((item) => {
                const isFuture =
                  selectedYear > currentYear ||
                  (selectedYear === currentYear && item > currentMonth);
                const isActive = item === selectedMonth;
                return (
                  <button
                    key={item}
                    type="button"
                    disabled={isFuture}
                    onClick={() => setSelectedMonth(item)}
                    className={`rounded-2xl px-3 py-3 text-sm font-semibold transition ${
                      isActive
                        ? 'bg-primary text-white shadow-sm'
                        : isFuture
                          ? 'cursor-not-allowed bg-gray-50 text-gray-300'
                          : 'bg-gray-50 text-text-primary active:scale-[0.98]'
                    }`}
                  >
                    {item}月
                  </button>
                );
              })}
            </div>
          </div>
        </div>

        <div className="mt-4 grid grid-cols-2 gap-3">
          <button
            type="button"
            onClick={() => {
              setSelectedYear(currentYear);
              setSelectedMonth(currentMonth);
            }}
            className="rounded-2xl bg-gray-100 py-3 text-base font-semibold text-text-secondary"
          >
            本月
          </button>
          <button
            type="button"
            onClick={handleConfirm}
            className="rounded-2xl bg-primary py-3 text-base font-semibold text-white shadow-sm"
          >
            确定
          </button>
        </div>
      </div>
    </div>
  );
}
