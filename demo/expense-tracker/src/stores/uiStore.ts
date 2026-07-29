import { create } from 'zustand';

interface ToastState {
  message: string;
  type: 'success' | 'error';
}

interface ConfirmDialogState {
  title: string;
  message: string;
  onConfirm: () => void;
}

interface UIStore {
  currentYear: number;
  currentMonth: number;
  selectedDate: string | null;
  toast: ToastState | null;
  confirmDialog: ConfirmDialogState | null;
  setMonth: (year: number, month: number) => void;
  setSelectedDate: (date: string | null) => void;
  goToToday: () => void;
  showToast: (message: string, type?: ToastState['type']) => void;
  hideToast: () => void;
  showConfirm: (dialog: ConfirmDialogState) => void;
  hideConfirm: () => void;
}

const now = new Date();

export const useUIStore = create<UIStore>((set) => ({
  currentYear: now.getFullYear(),
  currentMonth: now.getMonth() + 1,
  selectedDate: null,
  toast: null,
  confirmDialog: null,

  setMonth: (year, month) => set({ currentYear: year, currentMonth: month, selectedDate: null }),

  setSelectedDate: (date) => set({ selectedDate: date }),

  goToToday: () => {
    const today = new Date();
    set({
      currentYear: today.getFullYear(),
      currentMonth: today.getMonth() + 1,
      selectedDate: null,
    });
  },

  showToast: (message, type = 'success') => set({ toast: { message, type } }),

  hideToast: () => set({ toast: null }),

  showConfirm: (dialog) => set({ confirmDialog: dialog }),

  hideConfirm: () => set({ confirmDialog: null }),
}));
