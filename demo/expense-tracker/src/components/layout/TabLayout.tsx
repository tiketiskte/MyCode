import { Outlet } from 'react-router-dom';
import { TabBar } from './TabBar';

export function TabLayout() {
  return (
    <>
      <Outlet />
      <TabBar />
    </>
  );
}
