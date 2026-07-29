import { useMemo } from 'react';
import { Link } from 'react-router-dom';
import {
  DayCalendar,
  EmptyState,
  MonthPicker,
  RecordList,
  StatCard,
} from '@/components/record';
import { useMonthlyStats, useMonthNavigation, useRecords } from '@/hooks';
import { useUIStore } from '@/stores';

export function HomePage() {
  const { records, allMonthRecords, isLoading, error, currentYear, currentMonth, selectedDate } =
    useRecords();
  const stats = useMonthlyStats(records, currentYear, currentMonth, selectedDate);
  const { goToPrevMonth, goToNextMonth, goToToday, canGoNext, isViewingCurrentMonth } =
    useMonthNavigation();
  const { setMonth, setSelectedDate } = useUIStore();

  const recordDates = useMemo(
    () => [...new Set(allMonthRecords.map((record) => record.date))],
    [allMonthRecords],
  );

  return (
    <div className="min-h-screen pb-24">
      <header className="bg-gradient-primary px-4 pb-8 pt-6 text-white">
        <div className="mb-5 flex items-center justify-between">
          <div>
            <h1 className="text-2xl font-bold tracking-wide">简记</h1>
            <p className="mt-1 text-sm text-white/80">轻松掌握每一笔收支</p>
          </div>
          <Link
            to="/add"
            className="rounded-full bg-white px-4 py-2 text-sm font-semibold text-primary shadow-sm"
          >
            + 记一笔
          </Link>
        </div>

        <MonthPicker
          year={currentYear}
          month={currentMonth}
          canGoNext={canGoNext}
          isViewingCurrentMonth={isViewingCurrentMonth}
          onPrev={goToPrevMonth}
          onNext={goToNextMonth}
          onSelectMonth={setMonth}
          onGoToday={goToToday}
        />
      </header>

      <main className="space-y-4 px-4">
        <StatCard stats={stats} />

        <DayCalendar
          year={currentYear}
          month={currentMonth}
          recordDates={recordDates}
          selectedDate={selectedDate}
          onSelectDate={setSelectedDate}
        />

        <section>
          <h2 className="mb-3 px-1 text-sm font-semibold text-text-secondary">
            {selectedDate ? '当日流水' : '本月流水'}
          </h2>

          {isLoading ? (
            <p className="py-8 text-center text-sm text-text-secondary">加载中...</p>
          ) : error ? (
            <p className="py-8 text-center text-sm text-expense">{error}</p>
          ) : records.length === 0 ? (
            <EmptyState />
          ) : (
            <RecordList records={records} />
          )}
        </section>
      </main>
    </div>
  );
}
