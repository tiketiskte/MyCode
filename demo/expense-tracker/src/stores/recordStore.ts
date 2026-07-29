import { create } from 'zustand';
import { recordService } from '@/services/recordService';
import type { CreateRecordInput, Record, UpdateRecordInput } from '@/types/record';

interface RecordStore {
  records: Record[];
  isLoading: boolean;
  error: string | null;
  fetchRecords: (year: number, month: number) => Promise<void>;
  addRecord: (data: CreateRecordInput, image?: File) => Promise<Record>;
  updateRecord: (id: string, data: UpdateRecordInput, image?: File) => Promise<Record>;
  removeRecord: (id: string) => Promise<void>;
  getRecordById: (id: string) => Promise<Record | undefined>;
}

export const useRecordStore = create<RecordStore>((set) => ({
  records: [],
  isLoading: false,
  error: null,

  fetchRecords: async (year, month) => {
    set({ isLoading: true, error: null });
    try {
      const records = await recordService.getByMonth(year, month);
      set({ records, isLoading: false });
    } catch (error) {
      set({
        isLoading: false,
        error: error instanceof Error ? error.message : '加载记录失败',
      });
    }
  },

  addRecord: async (data, image) => {
    const record = await recordService.create(data, image);
    set((state) => ({ records: [record, ...state.records] }));
    return record;
  },

  updateRecord: async (id, data, image) => {
    const record = await recordService.update(id, data, image);
    set((state) => ({
      records: state.records.map((item) => (item.id === id ? record : item)),
    }));
    return record;
  },

  removeRecord: async (id) => {
    await recordService.remove(id);
    set((state) => ({
      records: state.records.filter((item) => item.id !== id),
    }));
  },

  getRecordById: (id) => recordService.getById(id),
}));
