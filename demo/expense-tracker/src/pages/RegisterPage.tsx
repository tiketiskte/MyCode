import { useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { useAuthStore } from '@/stores/authStore';

export function RegisterPage() {
  const navigate = useNavigate();
  const { register } = useAuthStore();
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [displayName, setDisplayName] = useState('');
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    if (password.length < 4) {
      setError('密码至少4位');
      return;
    }
    setError('');
    setLoading(true);
    try {
      await register({
        username,
        password,
        display_name: displayName || undefined,
      });
      navigate('/');
    } catch (err: any) {
      setError(err.response?.data?.username?.[0] || err.response?.data?.error || '注册失败，请重试');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="flex min-h-screen flex-col items-center justify-center bg-surface px-6">
      <div className="w-full max-w-sm">
        <div className="mb-8 text-center">
          <h1 className="text-3xl font-bold text-primary">简记</h1>
          <p className="mt-2 text-sm text-text-secondary">创建新账号</p>
        </div>

        <form onSubmit={handleSubmit} className="space-y-4">
          <div>
            <input
              type="text"
              placeholder="用户名"
              value={username}
              onChange={(e) => setUsername(e.target.value)}
              className="w-full rounded-xl border border-gray-200 bg-white px-4 py-3 text-sm outline-none transition focus:border-primary"
              required
            />
          </div>
          <div>
            <input
              type="text"
              placeholder="显示名称（如：爸爸、妈妈）"
              value={displayName}
              onChange={(e) => setDisplayName(e.target.value)}
              className="w-full rounded-xl border border-gray-200 bg-white px-4 py-3 text-sm outline-none transition focus:border-primary"
            />
          </div>
          <div>
            <input
              type="password"
              placeholder="密码（至少4位）"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              className="w-full rounded-xl border border-gray-200 bg-white px-4 py-3 text-sm outline-none transition focus:border-primary"
              required
              minLength={4}
            />
          </div>

          {error && (
            <p className="text-center text-sm text-expense">{error}</p>
          )}

          <button
            type="submit"
            disabled={loading}
            className="w-full rounded-xl bg-primary py-3 text-sm font-semibold text-white transition active:bg-primary-dark disabled:opacity-60"
          >
            {loading ? '注册中...' : '注册'}
          </button>
        </form>

        <p className="mt-6 text-center text-sm text-text-secondary">
          已有账号？
          <Link to="/login" className="ml-1 text-primary font-medium">
            登录
          </Link>
        </p>
      </div>
    </div>
  );
}
