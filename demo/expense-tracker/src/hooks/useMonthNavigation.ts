import { useUIStore } from '@/stores';
import { isCurrentMonth } from '@/utils/date';

export function useMonthNavigation() {
  const { currentYear, currentMonth, setMonth, goToToday } = useUIStore();

  const goToPrevMonth = () => {
    const date = new Date(currentYear, currentMonth - 2, 1);
    setMonth(date.getFullYear(), date.getMonth() + 1);
  };

  const goToNextMonth = () => {
    const now = new Date();
    const next = new Date(currentYear, currentMonth, 1);
    if (
      next.getFullYear() > now.getFullYear() ||
      (next.getFullYear() === now.getFullYear() && next.getMonth() > now.getMonth())
    ) {
      return;
    }
    setMonth(next.getFullYear(), next.getMonth() + 1);
  };

  const canGoNext = (() => {
    const now = new Date();
    return !(
      currentYear > now.getFullYear() ||
      (currentYear === now.getFullYear() && currentMonth >= now.getMonth() + 1)
    );
  })();

  return {
    currentYear,
    currentMonth,
    goToPrevMonth,
    goToNextMonth,
    goToToday,
    canGoNext,
    isViewingCurrentMonth: isCurrentMonth(currentYear, currentMonth),
  };
}
