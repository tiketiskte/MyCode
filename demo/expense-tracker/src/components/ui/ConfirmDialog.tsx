import { useUIStore } from '@/stores/uiStore';
import { Button } from './Button';

export function ConfirmDialog() {
  const { confirmDialog, hideConfirm } = useUIStore();

  if (!confirmDialog) return null;

  const handleConfirm = () => {
    confirmDialog.onConfirm();
    hideConfirm();
  };

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/40 px-4">
      <div className="w-full max-w-sm rounded-xl bg-white p-5 shadow-xl">
        <h2 className="text-lg font-semibold text-text-primary">{confirmDialog.title}</h2>
        <p className="mt-2 text-sm text-text-secondary">{confirmDialog.message}</p>
        <div className="mt-5 flex gap-3">
          <Button variant="secondary" fullWidth onClick={hideConfirm}>
            取消
          </Button>
          <Button variant="danger" fullWidth onClick={handleConfirm}>
            确定
          </Button>
        </div>
      </div>
    </div>
  );
}
