import { useEffect } from 'react';
import { RouterProvider } from 'react-router-dom';
import { router } from './router';
import { useAuthStore } from '@/stores/authStore';

export default function App() {
  const loadUser = useAuthStore((s) => s.loadUser);
  const isAuthenticated = useAuthStore((s) => s.isAuthenticated);

  useEffect(() => {
    if (isAuthenticated) {
      loadUser();
    }
  }, []);

  return <RouterProvider router={router} />;
}
