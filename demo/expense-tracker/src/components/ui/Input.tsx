import type { InputHTMLAttributes } from 'react';

interface InputProps extends InputHTMLAttributes<HTMLInputElement> {
  label?: string;
  error?: string | null;
}

export function Input({ label, error, className = '', id, ...props }: InputProps) {
  const inputId = id ?? label;

  return (
    <div className="space-y-1.5">
      {label ? (
        <label htmlFor={inputId} className="block text-sm text-text-secondary">
          {label}
        </label>
      ) : null}
      <input
        id={inputId}
        className={`w-full rounded-lg border border-gray-200 bg-white px-3 py-2.5 text-text-primary outline-none transition focus:border-primary focus:ring-2 focus:ring-primary/20 ${className}`}
        {...props}
      />
      {error ? <p className="text-sm text-expense">{error}</p> : null}
    </div>
  );
}
