import { Link } from 'react-router-dom';
import { Button } from '@/components/ui';

export function EmptyState() {
  return (
    <section className="rounded-2xl bg-white px-6 py-12 text-center shadow-card">
      <p className="text-4xl">📝</p>
      <p className="mt-3 text-base font-semibold text-text-primary">暂无记录</p>
      <p className="mt-2 text-sm text-text-secondary">选个日期开始记账，或点击下方按钮</p>
      <Link to="/add" className="mt-5 inline-block">
        <Button className="rounded-full px-8">记一笔</Button>
      </Link>
    </section>
  );
}
