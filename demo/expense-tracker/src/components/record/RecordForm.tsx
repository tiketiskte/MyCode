import { useEffect, useState } from 'react';
import type { RecordType } from '@/types/record';
import { Button, Input } from '@/components/ui';
import { formatLiveDateTime, getNowDateTime } from '@/utils/date';
import { validateAmount } from '@/utils/validate';
import { QUICK_NOTES, RECORD_CATEGORIES } from '@/utils/constants';

export interface RecordFormData {
  type: RecordType;
  amount: number;
  note: string;
  category?: string;
  subcategory?: string;
  date: string;
  time: string;
}

interface RecordFormProps {
  submitLabel?: string;
  initialType?: RecordType;
  initialAmount?: string;
  initialNote?: string;
  initialCategory?: string;
  initialSubcategory?: string;
  initialDate?: string;
  initialTime?: string;
  showLiveClock?: boolean;
  onSubmit: (data: RecordFormData) => Promise<void>;
}

export function RecordForm({
  submitLabel = '保存',
  initialType = 'expense',
  initialAmount = '',
  initialNote = '',
  initialCategory,
  initialSubcategory,
  initialDate,
  initialTime,
  showLiveClock = true,
  onSubmit,
}: RecordFormProps) {
  const initialDateTime = getNowDateTime();
  const [type, setType] = useState<RecordType>(initialType);
  const [amount, setAmount] = useState(initialAmount);
  const [note, setNote] = useState(initialNote);
  const [category, setCategory] = useState(initialCategory ?? RECORD_CATEGORIES[initialType][0].id);
  const [subcategory, setSubcategory] = useState(
    initialSubcategory ?? RECORD_CATEGORIES[initialType][0].children[0].id,
  );
  const [date, setDate] = useState(initialDate ?? initialDateTime.date);
  const [time, setTime] = useState(initialTime ?? initialDateTime.time);
  const [error, setError] = useState<string | null>(null);
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [now, setNow] = useState(new Date());

  useEffect(() => {
    if (!showLiveClock) return;
    const timer = window.setInterval(() => setNow(new Date()), 1000);
    return () => window.clearInterval(timer);
  }, [showLiveClock]);

  const categories = RECORD_CATEGORIES[type];
  const selectedCategory = categories.find((item) => item.id === category) ?? categories[0];
  const subcategories = selectedCategory.children;
  const selectedSubcategory =
    subcategories.find((item) => item.id === subcategory) ?? subcategories[0];
  const quickNotes = QUICK_NOTES[selectedSubcategory.id as keyof typeof QUICK_NOTES] ?? [];

  useEffect(() => {
    setCategory((current) => {
      if (categories.some((item) => item.id === current)) return current;
      return categories[0]?.id;
    });
  }, [categories]);

  useEffect(() => {
    setSubcategory((current) => {
      if (subcategories.some((item) => item.id === current)) return current;
      return subcategories[0]?.id;
    });
  }, [subcategories]);

  const handleSubmit = async (event: React.FormEvent) => {
    event.preventDefault();
    const validationError = validateAmount(amount);
    if (validationError) {
      setError(validationError);
      return;
    }
    const submitDateTime = showLiveClock ? getNowDateTime() : { date, time };

    setIsSubmitting(true);
    try {
      await onSubmit({
        type,
        amount: Number(amount),
        note: note.trim(),
        category,
        subcategory,
        date: submitDateTime.date,
        time: submitDateTime.time,
      });
    } finally {
      setIsSubmitting(false);
    }
  };

  return (
    <form onSubmit={handleSubmit} className="space-y-5">
      {showLiveClock ? (
        <div className="rounded-2xl bg-primary/8 px-4 py-3 text-center">
          <p className="text-xs text-text-secondary">记录时间（保存时自动获取）</p>
          <p className="mt-1 text-sm font-semibold text-primary">{formatLiveDateTime(now)}</p>
        </div>
      ) : null}

      <div className="grid grid-cols-2 gap-2 rounded-2xl bg-gray-100 p-1.5">
        <button
          type="button"
          onClick={() => setType('expense')}
          className={`rounded-xl py-3 text-sm font-semibold transition ${
            type === 'expense' ? 'bg-white text-expense shadow-sm' : 'text-text-secondary'
          }`}
        >
          支出
        </button>
        <button
          type="button"
          onClick={() => setType('income')}
          className={`rounded-xl py-3 text-sm font-semibold transition ${
            type === 'income' ? 'bg-white text-income shadow-sm' : 'text-text-secondary'
          }`}
        >
          收入
        </button>
      </div>

      <div className="space-y-3">
        <p className="text-sm text-text-secondary">分类</p>
        <div className="grid grid-cols-4 gap-2">
          {categories.map((item) => {
            const isActive = item.id === category;
            return (
              <button
                key={item.id}
                type="button"
                onClick={() => {
                  setCategory(item.id);
                  setSubcategory(item.children[0].id);
                }}
                className={`flex min-h-[4.25rem] flex-col items-center justify-center rounded-2xl border px-2 py-2 text-center text-xs font-medium transition ${
                  isActive
                    ? 'border-primary bg-primary/10 text-primary'
                    : 'border-gray-100 bg-white text-text-secondary'
                }`}
              >
                <span className="text-xl leading-none">{item.icon}</span>
                <span className="mt-1 leading-tight">{item.name}</span>
              </button>
            );
          })}
        </div>
      </div>

      <div className="space-y-3">
        <div className="flex items-center justify-between">
          <p className="text-sm text-text-secondary">细分</p>
          <p className="text-xs text-text-secondary">
            {selectedCategory.icon} {selectedCategory.name}
          </p>
        </div>
        <div className="grid grid-cols-3 gap-2">
          {subcategories.map((item) => {
            const isActive = item.id === subcategory;
            return (
              <button
                key={item.id}
                type="button"
                onClick={() => setSubcategory(item.id)}
                className={`flex min-h-[3.5rem] flex-col items-center justify-center rounded-2xl border px-2 py-2 text-center text-xs font-medium transition ${
                  isActive
                    ? 'border-primary bg-primary/10 text-primary'
                    : 'border-gray-100 bg-white text-text-primary'
                }`}
              >
                <span className="text-lg leading-none">{item.icon}</span>
                <span className="mt-1 leading-tight">{item.name}</span>
              </button>
            );
          })}
        </div>
      </div>

      <div>
        <label htmlFor="amount" className="mb-2 block text-sm text-text-secondary">
          金额
        </label>
        <div className="flex items-center rounded-2xl border-2 border-gray-100 bg-white px-4 py-4 focus-within:border-primary">
          <span className="mr-2 text-3xl font-light text-text-secondary">¥</span>
          <input
            id="amount"
            type="text"
            inputMode="decimal"
            autoFocus
            placeholder="0.00"
            value={amount}
            onChange={(event) => {
              setAmount(event.target.value);
              setError(null);
            }}
            className="w-full bg-transparent text-4xl font-bold text-text-primary outline-none"
          />
        </div>
        {error ? <p className="mt-2 text-sm text-expense">{error}</p> : null}
      </div>

      <Input
        label="备注（可选）"
        placeholder="例如：午餐、地铁、工资..."
        value={note}
        onChange={(event) => setNote(event.target.value)}
      />

      {quickNotes.length > 0 ? (
        <div className="space-y-2">
          <p className="text-sm text-text-secondary">常用选项</p>
          <div className="flex flex-wrap gap-2">
            {quickNotes.map((item) => (
              <button
                key={item}
                type="button"
                onClick={() => setNote(item)}
                className={`rounded-full border px-3 py-1.5 text-sm transition ${
                  note === item
                    ? 'border-primary bg-primary/10 text-primary'
                    : 'border-gray-200 bg-white text-text-secondary'
                }`}
              >
                {item}
              </button>
            ))}
          </div>
        </div>
      ) : null}

      {!showLiveClock ? (
        <div className="grid grid-cols-2 gap-3">
          <Input
            label="日期"
            type="date"
            value={date}
            max={initialDateTime.date}
            onChange={(event) => setDate(event.target.value)}
          />
          <Input
            label="时间"
            type="time"
            value={time}
            onChange={(event) => setTime(event.target.value)}
          />
        </div>
      ) : null}

      <Button type="submit" fullWidth disabled={isSubmitting} className="rounded-2xl py-3.5 text-base">
        {isSubmitting ? '保存中...' : submitLabel}
      </Button>
    </form>
  );
}
