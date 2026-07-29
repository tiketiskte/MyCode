import type { ReactNode } from 'react';
import { useNavigate } from 'react-router-dom';

interface PageHeaderProps {
  title: string;
  showBack?: boolean;
  rightSlot?: ReactNode;
}

export function PageHeader({ title, showBack = false, rightSlot }: PageHeaderProps) {
  const navigate = useNavigate();

  return (
    <header className="sticky top-0 z-10 flex items-center justify-between border-b border-gray-100 bg-white/95 px-4 py-3 pt-safe backdrop-blur">
      <div className="flex min-w-0 items-center gap-2">
        {showBack ? (
          <button
            type="button"
            aria-label="返回"
            onClick={() => navigate(-1)}
            className="flex h-9 w-9 items-center justify-center rounded-full bg-surface text-lg text-text-primary"
          >
            ‹
          </button>
        ) : (
          <span className="w-9" />
        )}
        <h1 className="truncate text-lg font-semibold">{title}</h1>
      </div>
      <div className="min-w-[2rem]">{rightSlot}</div>
    </header>
  );
}
