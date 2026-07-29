import { NavLink } from "react-router-dom";

const tabs = [
  { to: "/", label: "明细", icon: "📋" },
  { to: "/add", label: "记账", icon: "✏️" },
  { to: "/history", label: "历史", icon: "📮" },
  { to: "/profile", label: "我的", icon: "👤" },
];

export function TabBar() {
  return (
    <nav className="fixed inset-x-0 bottom-0 z-40 border-t border-gray-100 bg-white/95 backdrop-blur">
      <div className="mx-auto flex max-w-app items-center justify-around px-2 pb-safe pt-2">
        {tabs.map((tab) => (
          <NavLink
            key={tab.to}
            to={tab.to}
            end={tab.to === "/"}
            className={({ isActive }) =>
              `flex min-w-[4.5rem] flex-col items-center gap-0.5 rounded-2xl px-3 py-1.5 text-xs transition ${
                isActive ? "font-semibold text-primary" : "text-text-secondary"
              }`
            }
          >
            {({ isActive }) => (
              <>
                <span className={`text-xl ${isActive ? "scale-110" : ""}`}>{tab.icon}</span>
                <span>{tab.label}</span>
              </>
            )}
          </NavLink>
        ))}
      </div>
    </nav>
  );
}
