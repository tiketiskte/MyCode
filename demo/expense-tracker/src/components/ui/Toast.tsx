import { useEffect } from 'react';
import { useUIStore } from '@/stores/uiStore';

export function Toast() {
  const { toast, hideToast } = useUIStore();

  useEffect(() => {
    if (!toast) return;
    const timer = window.setTimeout(hideToast, 2400);
    return () => window.clearTimeout(timer);
  }, [toast, hideToast]);

  if (!toast) return null;

  return (
    <div className="pointer-events-none fixed inset-x-0 top-4 z-50 flex justify-center px-4">
      <div
        className={`rounded-lg px-4 py-2 text-sm text-white shadow-lg ${
          toast.type === 'success' ? 'bg-gray-900' : 'bg-expense'
        }`}
        role="status"
      >
        {toast.message}
      </div>
    </div>
  );
}
