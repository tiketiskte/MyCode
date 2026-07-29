import { create } from 'zustand';
import api from '@/services/api';
import type { User } from '@/types/user';

interface LoginData {
  username: string;
  password: string;
}

interface RegisterData {
  username: string;
  password: string;
  display_name?: string;
}

interface AuthState {
  user: User | null;
  isAuthenticated: boolean;
  isLoading: boolean;
  login: (data: LoginData) => Promise<void>;
  register: (data: RegisterData) => Promise<void>;
  logout: () => void;
  loadUser: () => Promise<void>;
  updateProfile: (data: { display_name?: string; username?: string }) => Promise<void>;
}

export const useAuthStore = create<AuthState>((set) => ({
  user: null,
  isAuthenticated: !!localStorage.getItem('access_token'),
  isLoading: false,

  login: async (data) => {
    const res = await api.post('/auth/login/', data);
    localStorage.setItem('access_token', res.data.access);
    localStorage.setItem('refresh_token', res.data.refresh);
    localStorage.setItem('user', JSON.stringify(res.data.user));
    set({ user: res.data.user, isAuthenticated: true });
  },

  register: async (data) => {
    const res = await api.post('/auth/register/', data);
    localStorage.setItem('access_token', res.data.access);
    localStorage.setItem('refresh_token', res.data.refresh);
    localStorage.setItem('user', JSON.stringify(res.data.user));
    set({ user: res.data.user, isAuthenticated: true });
  },

  logout: () => {
    localStorage.removeItem('access_token');
    localStorage.removeItem('refresh_token');
    localStorage.removeItem('user');
    set({ user: null, isAuthenticated: false });
  },

  loadUser: async () => {
    const token = localStorage.getItem('access_token');
    if (!token) {
      set({ user: null, isAuthenticated: false, isLoading: false });
      return;
    }
    try {
      const res = await api.get('/auth/me/');
      localStorage.setItem('user', JSON.stringify(res.data));
      set({ user: res.data, isAuthenticated: true, isLoading: false });
    } catch {
      set({ user: null, isAuthenticated: false, isLoading: false });
    }
  },

  updateProfile: async (data) => {
    const res = await api.patch('/auth/me/', data);
    localStorage.setItem('user', JSON.stringify(res.data));
    set({ user: res.data });
  },

  updateAvatar: async (file: File) => {
    const formData = new FormData();
    formData.append('avatar', file);
    const res = await api.patch('/auth/me/', formData);
    localStorage.setItem('user', JSON.stringify(res.data));
    set({ user: res.data });
  },
}));
