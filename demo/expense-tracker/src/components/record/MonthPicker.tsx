import { useState } from 'react';
import { formatMonthLabel } from '@/utils/date';
import { MonthSelector } from './MonthSelector';

interface MonthPickerProps {
  year: number;
  month: number;
  canGoNext: boolean;
  isViewingCurrentMonth: boolean;
  onPrev: () => void;
  onNext: () => void;
  onSelectMonth: (year: number, month: number) => void;
  onGoToday: () => void;
}

export function MonthPicker({
  year,
  month,
  canGoNext,
  isViewingCurrentMonth,
  onPrev,
  onNext,
  onSelectMonth,
  onGoToday,
}: MonthPickerProps) {
  const [showSelector, setShowSelector] = useState(false);

  return (
    <>
      <div className="flex items-center gap-2">
        <button
          type="button"
          aria-label="上一月"
          onClick={onPrev}
          className="flex h-10 w-10 items-center justify-center rounded-full bg-white/20 text-white backdrop-blur transition active:scale-95"
        >
          ‹
        </button>

        <button
          type="button"
          onClick={() => setShowSelector(true)}
          className="flex-1 rounded-2xl bg-white/15 px-4 py-2 text-center backdrop-blur transition active:scale-[0.98]"
        >
          <span className="text-lg font-bold text-white">{formatMonthLabel(year, month)}</span>
          <span className="mt-0.5 block text-xs text-white/80">点击选择月份</span>
        </button>

        <button
          type="button"
          aria-label="下一月"
          onClick={onNext}
          disabled={!canGoNext}
          className="flex h-10 w-10 items-center justify-center rounded-full bg-white/20 text-white backdrop-blur transition active:scale-95 disabled:opacity-30"
        >
          ›
        </button>
      </div>

      {!isViewingCurrentMonth ? (
        <button
          type="button"
          onClick={onGoToday}
          className="mt-2 w-full rounded-full bg-white/15 py-1.5 text-xs font-medium text-white backdrop-blur"
        >
          回到本月
        </button>
      ) : null}

      {showSelector ? (
        <MonthSelector
          year={year}
          month={month}
          onSelect={onSelectMonth}
          onClose={() => setShowSelector(false)}
        />
      ) : null}
    </>
  );
}
