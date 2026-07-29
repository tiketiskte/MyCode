import { useEffect, useRef, useState } from 'react';
import { useNavigate, useParams } from 'react-router-dom';
import { RecordForm, type RecordFormData } from '@/components/record';
import { PageHeader } from '@/components/layout';
import { Button } from '@/components/ui';
import { useRecordStore, useUIStore } from '@/stores';
import type { Record } from '@/types';
import { getRecordCategory, getRecordSubcategory } from '@/utils/category';
import { formatRecordDateTime } from '@/utils/date';
import { formatSignedAmount } from '@/utils/format';

export function RecordDetailPage() {
  const { id = '' } = useParams();
  const navigate = useNavigate();
  const getRecordById = useRecordStore((state) => state.getRecordById);
  const updateRecord = useRecordStore((state) => state.updateRecord);
  const removeRecord = useRecordStore((state) => state.removeRecord);
  const fetchRecords = useRecordStore((state) => state.fetchRecords);
  const { currentYear, currentMonth, setMonth, showToast, showConfirm } = useUIStore();

  const [record, setRecord] = useState<Record | null>(null);
  const [isEditing, setIsEditing] = useState(false);
  const [isLoading, setIsLoading] = useState(true);
  const [imageFile, setImageFile] = useState<File | null>(null);
  const [imagePreview, setImagePreview] = useState<string | null>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    let mounted = true;
    const loadRecord = async () => {
      setIsLoading(true);
      const data = await getRecordById(id);
      if (mounted) {
        setRecord(data ?? null);
        setIsLoading(false);
      }
    };
    void loadRecord();
    return () => { mounted = false; };
  }, [getRecordById, id]);

  const handleImageSelect = (e: React.ChangeEvent<HTMLInputElement>) => {
    const file = e.target.files?.[0];
    if (!file) return;
    setImageFile(file);
    const reader = new FileReader();
    reader.onload = (event) => setImagePreview(event.target?.result as string);
    reader.readAsDataURL(file);
  };

  const handleUpdate = async (data: RecordFormData) => {
    if (!record) return;
    const updated = await updateRecord(
      record.id,
      {
        type: data.type,
        amount: data.amount,
        note: data.note,
        category: data.category,
        subcategory: data.subcategory,
        date: data.date,
        time: data.time,
      },
      imageFile || undefined,
    );
    const [year, month] = updated.date.split('-').map(Number);
    setMonth(year, month);
    await fetchRecords(year, month);
    setRecord(updated);
    setIsEditing(false);
    setImageFile(null);
    setImagePreview(null);
    showToast('已保存');
  };

  const handleDelete = () => {
    if (!record) return;
    showConfirm({
      title: '删除记录',
      message: '确定删除这条记录吗？此操作不可恢复。',
      onConfirm: async () => {
        await removeRecord(record.id);
        await fetchRecords(currentYear, currentMonth);
        showToast('已删除');
        navigate('/');
      },
    });
  };

  if (isLoading) {
    return (
      <div className="min-h-screen bg-surface">
        <PageHeader title="记录详情" showBack />
        <p className="px-4 py-8 text-center text-sm text-text-secondary">加载中...</p>
      </div>
    );
  }

  if (!record) {
    return (
      <div className="min-h-screen bg-surface">
        <PageHeader title="记录详情" showBack />
        <p className="px-4 py-8 text-center text-sm text-expense">记录不存在</p>
      </div>
    );
  }

  const category = getRecordCategory(record.type, record.category);
  const subcategory = getRecordSubcategory(record.type, record.category, record.subcategory);

  return (
    <div className="min-h-screen bg-surface pb-6">
      <PageHeader title="记录详情" showBack />

      <main className="space-y-4 px-4 py-4">
        {isEditing ? (
          <div className="rounded-2xl bg-white p-4 shadow-card">
            {/* 编辑模式下的图片上传 */}
            <div className="mb-4">
              <p className="mb-2 text-sm text-text-secondary">修改图片（可选）</p>
              {imagePreview ? (
                <div className="relative inline-block">
                  <img src={imagePreview} alt="预览" className="h-32 w-32 rounded-xl border border-gray-200 object-cover" />
                  <button type="button" onClick={() => { setImageFile(null); setImagePreview(null); }}
                    className="absolute -right-2 -top-2 flex h-6 w-6 items-center justify-center rounded-full bg-expense text-xs text-white shadow">✕</button>
                </div>
              ) : record.image ? (
                <div className="relative inline-block">
                  <img src={record.image} alt="当前图片" className="h-32 w-32 rounded-xl border border-gray-200 object-cover" />
                  <button type="button" onClick={() => fileInputRef.current?.click()}
                    className="absolute -right-2 -top-2 flex h-6 w-6 items-center justify-center rounded-full bg-primary text-xs text-white shadow">✎</button>
                </div>
              ) : (
                <button type="button" onClick={() => fileInputRef.current?.click()}
                  className="flex h-20 w-32 items-center justify-center rounded-xl border-2 border-dashed border-gray-200 text-sm text-text-secondary transition hover:border-primary hover:text-primary">
                  <span>+ 添加图片</span>
                </button>
              )}
              <input ref={fileInputRef} type="file" accept="image/*" capture="environment"
                onChange={handleImageSelect} className="hidden" />
            </div>

            <RecordForm
              submitLabel="保存修改"
              initialType={record.type}
              initialAmount={String(record.amount)}
              initialNote={record.note}
              initialCategory={record.category}
              initialSubcategory={record.subcategory}
              initialDate={record.date}
              initialTime={record.time}
              showLiveClock={false}
              onSubmit={handleUpdate}
            />
          </div>
        ) : (
          <section className="space-y-5 rounded-2xl bg-white p-5 shadow-card">
            <div className="text-center">
              <p className={`text-3xl font-bold ${record.type === 'income' ? 'text-income' : 'text-expense'}`}>
                {formatSignedAmount(record.type, record.amount)}
              </p>
              <p className="mt-2 text-sm text-text-secondary">
                {record.type === 'income' ? '收入' : '支出'} · {formatRecordDateTime(record.date, record.time)}
              </p>
            </div>

            {record.image ? (
              <div>
                <p className="mb-2 text-xs text-text-secondary">单据图片</p>
                <img src={record.image} alt="单据" className="w-full max-h-80 rounded-xl border border-gray-100 object-contain bg-gray-50" />
              </div>
            ) : null}

            <div className="rounded-2xl bg-surface px-4 py-3">
              <p className="text-xs text-text-secondary">备注</p>
              <p className="mt-1 font-medium text-text-primary">{record.note.trim() || '未命名'}</p>
            </div>

            {record.category ? (
              <div className="rounded-2xl bg-surface px-4 py-3">
                <p className="text-xs text-text-secondary">分类</p>
                <p className="mt-1 font-medium text-text-primary">
                  {category.icon} {category.name}
                  {record.subcategory ? ` / ${subcategory.icon} ${subcategory.name}` : ''}
                </p>
              </div>
            ) : null}

            <div className="rounded-2xl bg-surface px-4 py-3">
              <p className="text-xs text-text-secondary">记录时间</p>
              <p className="mt-1 font-medium text-text-primary">{record.date} {record.time}</p>
            </div>

            <div className="grid grid-cols-2 gap-3 pt-2">
              <Button variant="secondary" onClick={() => setIsEditing(true)}>编辑</Button>
              <Button variant="danger" onClick={handleDelete}>删除</Button>
            </div>
          </section>
        )}
      </main>
    </div>
  );
}
