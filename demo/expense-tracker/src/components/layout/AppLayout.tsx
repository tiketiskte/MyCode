import { Outlet } from 'react-router-dom';
import { ConfirmDialog, Toast } from '@/components/ui';

export function AppLayout() {
  return (
    <div className="min-h-screen bg-surface text-text-primary">
      <div className="mx-auto min-h-screen w-full max-w-app">
        <Outlet />
      </div>
      <Toast />
      <ConfirmDialog />
    </div>
  );
}
