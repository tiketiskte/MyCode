import { Link } from 'react-router-dom';
import type { Record } from '@/types/record';
import { formatRecordDateTime } from '@/utils/date';
import { formatSignedAmount } from '@/utils/format';
import { getRecordCategory, getRecordSubcategory } from '@/utils/category';

interface RecordItemProps {
  record: Record;
}

function getRecordIcon(type: Record['type'], note: string) {
  if (type === 'income') return '💰';
  const text = note.trim();
  if (text.includes('餐') || text.includes('饭') || text.includes('食')) return '🍜';
  if (text.includes('车') || text.includes('地铁') || text.includes('交通')) return '🚇';
  if (text.includes('购') || text.includes('超市')) return '🛒';
  return '💸';
}

export function RecordItem({ record }: RecordItemProps) {
  const displayNote = record.note.trim() || '未命名';
  const amountClass = record.type === 'income' ? 'text-income' : 'text-expense';
  const category = getRecordCategory(record.type, record.category);
  const subcategory = getRecordSubcategory(record.type, record.category, record.subcategory);

  return (
    <Link
      to={`/record/${record.id}`}
      className="flex items-center gap-3 rounded-2xl bg-white px-4 py-3.5 shadow-card transition active:scale-[0.99]"
    >
      <div
        className={`flex h-11 w-11 shrink-0 items-center justify-center rounded-2xl text-xl ${
          record.type === 'income' ? 'bg-income/10' : 'bg-expense/10'
        }`}
      >
        {record.subcategory ? subcategory.icon : record.category ? category.icon : getRecordIcon(record.type, record.note)}
      </div>
      <div className="min-w-0 flex-1">
        <p className="truncate font-medium text-text-primary">{displayNote}</p>
        <p className="mt-0.5 truncate text-xs text-text-secondary">
          {record.category
            ? `${category.name}${record.subcategory ? ' / ' + subcategory.name : ''} . `
            : ''}
          {formatRecordDateTime(record.date, record.time)}
        </p>
      </div>
      {record.image ? (
        <img
          src={record.image}
          alt=""
          className="h-9 w-9 shrink-0 rounded-lg border border-gray-100 object-cover"
        />
      ) : null}
      <p className={`shrink-0 text-base font-bold ${amountClass}`}>
        {formatSignedAmount(record.type, record.amount)}
      </p>
    </Link>
  );
}
