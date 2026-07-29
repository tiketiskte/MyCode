import { useRef, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { RecordForm, type RecordFormData } from '@/components/record';
import { useRecordStore, useUIStore } from '@/stores';

export function AddRecordPage() {
  const navigate = useNavigate();
  const addRecord = useRecordStore((state) => state.addRecord);
  const fetchRecords = useRecordStore((state) => state.fetchRecords);
  const { setMonth, showToast } = useUIStore();
  const [imageFile, setImageFile] = useState<File | null>(null);
  const [imagePreview, setImagePreview] = useState<string | null>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);

  const handleImageSelect = (e: React.ChangeEvent<HTMLInputElement>) => {
    const file = e.target.files?.[0];
    if (!file) return;
    setImageFile(file);
    const reader = new FileReader();
    reader.onload = (event) => setImagePreview(event.target?.result as string);
    reader.readAsDataURL(file);
  };

  const removeImage = () => {
    setImageFile(null);
    setImagePreview(null);
    if (fileInputRef.current) fileInputRef.current.value = '';
  };

  const handleSubmit = async (data: RecordFormData) => {
    const record = await addRecord(
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
    const [year, month] = record.date.split('-').map(Number);
    setMonth(year, month);
    await fetchRecords(year, month);
    showToast(`已保存 · ${data.date} ${data.time}`);
    navigate('/');
  };

  return (
    <div className="min-h-screen pb-24">
      <header className="bg-gradient-primary px-4 pb-6 pt-6 text-white">
        <h1 className="text-2xl font-bold">记一笔</h1>
        <p className="mt-1 text-sm text-white/80">保存时将自动记录当前时间</p>
      </header>
      <main className="px-4 py-4">
        <div className="rounded-2xl bg-white p-4 shadow-card">
          {/* 图片上传 */}
          <div className="mb-4">
            <p className="mb-2 text-sm text-text-secondary">上传单据（可选）</p>
            {imagePreview ? (
              <div className="relative inline-block">
                <img
                  src={imagePreview}
                  alt="预览"
                  className="h-32 w-32 rounded-xl border border-gray-200 object-cover"
                />
                <button
                  type="button"
                  onClick={removeImage}
                  className="absolute -right-2 -top-2 flex h-6 w-6 items-center justify-center rounded-full bg-expense text-xs text-white shadow"
                >
                  ✕
                </button>
              </div>
            ) : (
              <button
                type="button"
                onClick={() => fileInputRef.current?.click()}
                className="flex h-20 w-32 items-center justify-center rounded-xl border-2 border-dashed border-gray-200 text-sm text-text-secondary transition hover:border-primary hover:text-primary"
              >
                <span>+ 拍照</span>
              </button>
            )}
            <input
              ref={fileInputRef}
              type="file"
              accept="image/*"
              capture="environment"
              onChange={handleImageSelect}
              className="hidden"
            />
          </div>

          <RecordForm onSubmit={handleSubmit} />
        </div>
      </main>
    </div>
  );
}
