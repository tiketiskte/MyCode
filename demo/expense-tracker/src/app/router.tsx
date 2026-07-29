import { lazy, Suspense } from "react";
import { createBrowserRouter, Navigate } from "react-router-dom";
import { AppLayout, PageLoader, TabLayout } from "@/components/layout";
import { useAuthStore } from "@/stores/authStore";

const HomePage = lazy(() => import("@/pages/HomePage").then((m) => ({ default: m.HomePage })));
const AddRecordPage = lazy(() => import("@/pages/AddRecordPage").then((m) => ({ default: m.AddRecordPage })));
const HistoryPage = lazy(() => import("@/pages/HistoryPage").then((m) => ({ default: m.HistoryPage })));
const RecordDetailPage = lazy(() => import("@/pages/RecordDetailPage").then((m) => ({ default: m.RecordDetailPage })));
const LoginPage = lazy(() => import("@/pages/LoginPage").then((m) => ({ default: m.LoginPage })));
const RegisterPage = lazy(() => import("@/pages/RegisterPage").then((m) => ({ default: m.RegisterPage })));
const ProfilePage = lazy(() => import("@/pages/ProfilePage").then((m) => ({ default: m.ProfilePage })));
const AdminDashboard = lazy(() => import("@/pages/AdminDashboard").then((m) => ({ default: m.AdminDashboard })));

function RequireAuth({ children }: { children: React.ReactNode }) {
  const isAuthenticated = useAuthStore((s) => s.isAuthenticated);
  if (!isAuthenticated) return <Navigate to="/login" replace />;
  return <>{children}</>;
}

function LazyPage({ children }: { children: React.ReactNode }) {
  return <Suspense fallback={<PageLoader />}>{children}</Suspense>;
}

export const router = createBrowserRouter([
  { path: "/login", element: <LazyPage><LoginPage /></LazyPage> },
  { path: "/register", element: <LazyPage><RegisterPage /></LazyPage> },
  {
    element: <RequireAuth><AppLayout /></RequireAuth>,
    children: [
      {
        element: <TabLayout />,
        children: [
          { path: "/", element: <LazyPage><HomePage /></LazyPage> },
          { path: "/add", element: <LazyPage><AddRecordPage /></LazyPage> },
          { path: "/history", element: <LazyPage><HistoryPage /></LazyPage> },
        ],
      },
      { path: "/record/:id", element: <LazyPage><RecordDetailPage /></LazyPage> },
    ],
  },
  { path: "/profile", element: <RequireAuth><LazyPage><ProfilePage /></LazyPage></RequireAuth> },
  { path: "/admin", element: <RequireAuth><LazyPage><AdminDashboard /></LazyPage></RequireAuth> },
]);
