import { useMemo } from 'react';
import { formatMonthLabel, getMonthDateRange, isFutureDate, isToday, toDateString } from '@/utils/date';

interface DayCalendarProps {
  year: number;
  month: number;
  recordDates: string[];
  selectedDate: string | null;
  onSelectDate: (date: string | null) => void;
}

export function DayCalendar({
  year,
  month,
  recordDates,
  selectedDate,
  onSelectDate,
}: DayCalendarProps) {
  const { daysInMonth } = getMonthDateRange(year, month);
  const recordDateSet = useMemo(() => new Set(recordDates), [recordDates]);
  const firstWeekday = new Date(year, month - 1, 1).getDay();
  const days = Array.from({ length: daysInMonth }, (_, index) => index + 1);

  const handleSelectDay = (day: number) => {
    const dateStr = toDateString(year, month, day);
    if (isFutureDate(dateStr)) return;
    onSelectDate(selectedDate === dateStr ? null : dateStr);
  };

  return (
    <section className="rounded-2xl bg-white p-4 shadow-card">
      <div className="mb-3 flex items-center justify-between">
        <h3 className="text-sm font-semibold text-text-primary">按日期查看</h3>
        <button
          type="button"
          onClick={() => onSelectDate(null)}
          className={`rounded-full px-3 py-1 text-xs font-medium transition ${
            !selectedDate ? 'bg-primary/10 text-primary' : 'bg-gray-100 text-text-secondary'
          }`}
        >
          整月
        </button>
      </div>

      <div className="mb-2 grid grid-cols-7 gap-1 text-center text-xs text-text-secondary">
        {['日', '一', '二', '三', '四', '五', '六'].map((label) => (
          <span key={label}>{label}</span>
        ))}
      </div>

      <div className="grid grid-cols-7 gap-1">
        {Array.from({ length: firstWeekday }).map((_, index) => (
          <span key={`empty-${index}`} />
        ))}
        {days.map((day) => {
          const dateStr = toDateString(year, month, day);
          const isFuture = isFutureDate(dateStr);
          const isSelected = selectedDate === dateStr;
          const hasRecords = recordDateSet.has(dateStr);
          const isTodayDate = isToday(dateStr);

          return (
            <button
              key={day}
              type="button"
              disabled={isFuture}
              onClick={() => handleSelectDay(day)}
              className={`relative flex h-10 flex-col items-center justify-center rounded-xl text-sm transition ${
                isSelected
                  ? 'bg-primary text-white shadow-sm'
                  : isTodayDate
                    ? 'bg-primary/10 font-semibold text-primary'
                    : isFuture
                      ? 'cursor-not-allowed text-gray-300'
                      : 'text-text-primary hover:bg-gray-50'
              }`}
            >
              {day}
              {hasRecords ? (
                <span
                  className={`absolute bottom-1 h-1 w-1 rounded-full ${
                    isSelected ? 'bg-white' : 'bg-primary'
                  }`}
                />
              ) : null}
            </button>
          );
        })}
      </div>

      {selectedDate ? (
        <p className="mt-3 text-center text-xs text-text-secondary">
          正在查看 {formatMonthLabel(year, month)} {selectedDate.split('-')[2]} 日
        </p>
      ) : null}
    </section>
  );
}
