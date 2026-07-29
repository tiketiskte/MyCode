import { useEffect, useMemo } from 'react';
import { useRecordStore } from '@/stores';
import { useUIStore } from '@/stores';

export function useRecords() {
  const { currentYear, currentMonth, selectedDate } = useUIStore();
  const { records, isLoading, error, fetchRecords } = useRecordStore();

  useEffect(() => {
    void fetchRecords(currentYear, currentMonth);
  }, [currentYear, currentMonth, fetchRecords]);

  const filteredRecords = useMemo(() => {
    if (!selectedDate) return records;
    return records.filter((record) => record.date === selectedDate);
  }, [records, selectedDate]);

  return {
    records: filteredRecords,
    allMonthRecords: records,
    isLoading,
    error,
    currentYear,
    currentMonth,
    selectedDate,
  };
}
