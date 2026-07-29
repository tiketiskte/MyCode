# 简记 — 技术设计文档（Tech Design）

| 项目 | 内容 |
|------|------|
| **文档版本** | v1.0 |
| **关联文档** | [PRD.md](./PRD.md) |
| **文档日期** | 2026-05-23 |
| **文档状态** | 初稿 |
| **适用范围** | MVP（v0.1）→ v2.0 演进 |

---

## 目录

1. [概述](#1-概述)
2. [技术栈选择](#2-技术栈选择)
3. [系统架构](#3-系统架构)
4. [项目结构](#4-项目结构)
5. [数据模型](#5-数据模型)
6. [API 设计（v2.0）](#6-api-设计v20)
7. [关键技术点](#7-关键技术点)
8. [部署方案](#8-部署方案)
9. [开发规范](#9-开发规范)
10. [版本演进计划](#10-版本演进计划)

---

## 1. 概述

### 1.1 设计目标

基于 PRD 中「极简、快速、本地优先」的产品定位，技术方案需满足：

- **零后端启动**：MVP 阶段纯前端 + 本地存储，无需服务器即可运行
- **3 秒记账**：UI 响应 < 200ms，数据写入异步不阻塞
- **跨平台**：一套 Web 代码覆盖手机浏览器、桌面浏览器、PWA
- **可演进**：架构预留 v2.0 云同步扩展点，避免推倒重来

### 1.2 设计原则

| 原则 | 说明 |
|------|------|
| **简单优先** | 不引入不必要的中间件和抽象层 |
| **本地优先** | 数据默认存本机，离线可用 |
| **分层清晰** | UI → Store → Service → DB，单向依赖 |
| **类型安全** | 全链路 TypeScript，减少运行时错误 |
| **渐进增强** | MVP 纯本地，后续按需加后端 |

---

## 2. 技术栈选择

### 2.1 总览

```
┌─────────────────────────────────────────────────────────┐
│                    MVP（v0.1 ~ v1.x）                    │
│                                                         │
│   React + TypeScript + Vite + Tailwind CSS              │
│   Zustand（状态） + Dexie.js（IndexedDB）                │
│   React Router（路由）                                   │
│                                                         │
│   部署：Vercel / Netlify / GitHub Pages（静态托管）      │
│   后端：无                                               │
│   数据库：IndexedDB（浏览器本地）                         │
└─────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────┐
│                    v2.0（云同步）                        │
│                                                         │
│   前端：同上 + vite-plugin-pwa                           │
│   后端：Node.js + Fastify（或 Express）                  │
│   数据库：PostgreSQL（云端）+ IndexedDB（本地缓存）       │
│   认证：JWT + 邮箱验证码                                  │
│   部署：Railway / Fly.io                                 │
└─────────────────────────────────────────────────────────┘
```

### 2.2 前端技术栈

| 类别 | 选型 | 版本建议 | 选型理由 |
|------|------|----------|----------|
| **框架** | React | 18+ | 组件化成熟、生态丰富、团队熟悉度高 |
| **语言** | TypeScript | 5+ | 类型安全，Record/Category 等模型编译期校验 |
| **构建工具** | Vite | 5+ | 冷启动快、HMR 即时、配置简洁 |
| **样式** | Tailwind CSS | 3+ | 快速实现 PRD 设计规范，响应式方便 |
| **状态管理** | Zustand | 4+ | 轻量（~1KB），无 boilerplate，适合小型 App |
| **路由** | React Router | 6+ | SPA 标准方案，支持懒加载 |
| **本地数据库** | Dexie.js | 4+ | IndexedDB 封装，支持索引查询、Schema 版本迁移 |
| **日期处理** | date-fns | 3+ | 轻量、Tree-shakable，处理月份切换/分组 |
| **UUID 生成** | crypto.randomUUID() | 原生 | 无需额外依赖，浏览器原生支持 |
| **图表（v1.0）** | Chart.js | 4+ | 轻量，满足分类饼图、趋势折线图 |
| **PWA（v1.x）** | vite-plugin-pwa | — | 离线缓存、可安装到主屏幕 |
| **代码规范** | ESLint + Prettier | — | 统一代码风格 |

**不选 Vue / Angular 的原因**：PRD 已倾向 React 生态；Zustand + Dexie 组合在 React 社区案例多。

**不选 Redux 的原因**：记账 App 状态简单（当前月份、记录列表、UI 状态），Zustand 足够且代码量更少。

### 2.3 后端技术栈

> MVP 阶段 **不需要后端**。以下方案供 v2.0 云同步使用。

| 类别 | 选型 | 选型理由 |
|------|------|----------|
| **运行时** | Node.js 20 LTS | 与前端同语言，共享 TypeScript 类型定义 |
| **Web 框架** | Fastify | 性能优于 Express，Schema 校验内置，适合小型 API |
| **ORM** | Drizzle ORM | 轻量、TypeScript-first、SQL 可控 |
| **认证** | JWT + 邮箱验证码 | 简单够用，无需 OAuth 复杂度 |
| **密码哈希** | bcrypt | 行业标准 |
| **参数校验** | Zod | 与 Drizzle 配合，前后端共享 Schema |
| **API 文档** | Swagger（@fastify/swagger） | 自动生成，便于前后端协作 |

**备选**：Python FastAPI — 若团队 Python 更强可选，但会失去前后端类型共享优势。

### 2.4 数据库选型

#### MVP 阶段：IndexedDB（via Dexie.js）

| 维度 | 说明 |
|------|------|
| **存储位置** | 用户浏览器本地 |
| **容量** | 通常 ≥ 50MB，远超 10,000 条记录需求 |
| **查询能力** | 支持索引（按 date 查月、按 type 过滤） |
| **离线** | 天然离线可用 |
| **局限** | 换设备/清浏览器数据会丢失；不可跨设备同步 |

#### v2.0 阶段：PostgreSQL + IndexedDB 双写

| 存储 | 角色 | 说明 |
|------|------|------|
| **IndexedDB** | 本地主存储 + 离线缓存 | 所有读写先走本地，保证响应速度 |
| **PostgreSQL** | 云端备份 + 多设备同步 | 用户登录后后台同步 |

```
用户操作 → 写入 IndexedDB（立即响应）
                ↓
         同步队列（offline queue）
                ↓
         联网时 → POST/PATCH/DELETE → PostgreSQL
                ↓
         其他设备拉取 → 合并到本地 IndexedDB
```

**不选 MongoDB 的原因**：记账数据结构固定、关系简单（Record 关联 Category），关系型数据库更合适。

**不选 SQLite（Web）的原因**：浏览器端 SQLite（sql.js）性能不如 IndexedDB 原生支持，且体积大。

**不选 localStorage 的原因**：容量有限（~5MB）、同步 API 阻塞 UI、不支持索引查询。

### 2.5 部署与基础设施

| 阶段 | 前端部署 | 后端部署 | 域名/HTTPS |
|------|----------|----------|------------|
| MVP | Vercel（推荐）或 Netlify | 无 | 平台自动提供 HTTPS |
| v1.x PWA | 同上 + Service Worker | 无 | 同上 |
| v2.0 | Vercel | Railway 或 Fly.io | 自定义域名 + TLS |

### 2.6 技术栈决策总结

| 层级 | MVP | v2.0 |
|------|-----|------|
| 前端框架 | React + TypeScript | 同左 |
| 构建 | Vite | 同左 + vite-plugin-pwa |
| 样式 | Tailwind CSS | 同左 |
| 状态管理 | Zustand | 同左 |
| 本地存储 | Dexie.js (IndexedDB) | 同左（作为本地缓存层） |
| 后端 | **无** | Node.js + Fastify |
| 云端数据库 | **无** | PostgreSQL |
| 认证 | **无** | JWT |

---

## 3. 系统架构

### 3.1 MVP 架构（纯前端）

```
┌──────────────────────────────────────────────────┐
│                   Browser                        │
│                                                  │
│  ┌──────────┐  ┌──────────┐  ┌──────────────┐   │
│  │  Pages   │  │Components│  │   Hooks      │   │
│  │ Home     │  │ StatCard │  │ useRecords   │   │
│  │ AddRecord│  │ RecList  │  │ useMonthNav  │   │
│  │ Detail   │  │ RecItem  │  │ useStats     │   │
│  └────┬─────┘  └────┬─────┘  └──────┬───────┘   │
│       │              │               │           │
│       └──────────────┼───────────────┘           │
│                      ▼                           │
│              ┌──────────────┐                    │
│              │ Zustand Store│                    │
│              │ recordStore  │                    │
│              │ uiStore      │                    │
│              └──────┬───────┘                    │
│                     ▼                            │
│              ┌──────────────┐                    │
│              │ Service Layer│                    │
│              │ RecordService│                    │
│              │ StatsService │                    │
│              └──────┬───────┘                    │
│                     ▼                            │
│              ┌──────────────┐                    │
│              │  Dexie.js    │                    │
│              │  (IndexedDB) │                    │
│              └──────────────┘                    │
└──────────────────────────────────────────────────┘
```

### 3.2 v2.0 架构（本地 + 云端）

```
┌──────── Browser ────────┐     ┌──── Server ────────────┐
│  UI → Store → Service   │     │  Fastify API           │
│         ↓               │     │    ↓                   │
│     IndexedDB           │◄───►│  PostgreSQL            │
│         ↓               │ sync│    ↓                   │
│     Sync Queue          │────►│  Auth (JWT)            │
└─────────────────────────┘     └────────────────────────┘
```

### 3.3 分层职责

| 层级 | 职责 | 规则 |
|------|------|------|
| **Pages** | 页面级组合，对接路由 | 不包含业务逻辑，调用 Store/Hook |
| **Components** | 可复用 UI 组件 | 纯展示 + 事件回调，不直接访问 DB |
| **Hooks** | 封装组件级逻辑 | 连接 Store 与 Component |
| **Store** | 全局状态管理 | 管理 UI 状态 + 缓存记录数据 |
| **Service** | 业务逻辑 | CRUD、统计计算、数据校验 |
| **DB** | 数据持久化 | Dexie 表定义、索引、迁移 |

---

## 4. 项目结构

### 4.1 目录总览

```
expense-tracker/
├── docs/                          # 文档
│   ├── PRD.md                     # 产品需求文档
│   └── tech-design.md             # 本文档
├── public/                        # 静态资源
│   ├── favicon.ico
│   └── icons/                     # PWA 图标（v1.x）
│       ├── icon-192.png
│       └── icon-512.png
├── src/
│   ├── app/                   # App.tsx + router.tsx
│   ├── main.tsx               # 应用启动入口
│   ├── pages/                 # 页面（与路由一一对应）
│   │   ├── HomePage.tsx
│   │   ├── AddRecordPage.tsx
│   │   └── RecordDetailPage.tsx
│   ├── components/            # UI 组件
│   │   ├── layout/
│   │   │   ├── AppLayout.tsx
│   │   │   ├── PageHeader.tsx
│   │   │   └── index.ts
│   │   ├── record/
│   │   │   ├── StatCard.tsx
│   │   │   ├── MonthPicker.tsx
│   │   │   ├── RecordList.tsx
│   │   │   ├── RecordItem.tsx
│   │   │   ├── RecordForm.tsx
│   │   │   ├── EmptyState.tsx
│   │   │   └── index.ts
│   │   └── ui/
│   │       ├── Button.tsx
│   │       ├── Input.tsx
│   │       ├── Toast.tsx
│   │       ├── ConfirmDialog.tsx
│   │       └── index.ts
│   ├── stores/                # Zustand 状态
│   │   ├── recordStore.ts
│   │   ├── uiStore.ts
│   │   └── index.ts
│   ├── services/              # 业务逻辑层
│   │   ├── recordService.ts
│   │   ├── statsService.ts
│   │   └── index.ts
│   ├── db/                    # 数据访问层
│   │   └── index.ts
│   ├── hooks/                 # 自定义 Hooks
│   │   ├── useRecords.ts
│   │   ├── useMonthlyStats.ts
│   │   ├── useMonthNavigation.ts
│   │   └── index.ts
│   ├── types/                 # TypeScript 类型定义
│   │   ├── record.ts
│   │   ├── stats.ts
│   │   └── index.ts
│   ├── utils/                 # 工具函数
│   │   ├── format.ts
│   │   ├── validate.ts
│   │   ├── date.ts
│   │   ├── constants.ts
│   │   └── index.ts
│   └── styles/                # 全局样式
│       └── global.css
│
├── index.html                     # HTML 入口
├── package.json
├── tsconfig.json
├── tsconfig.app.json
├── vite.config.ts
├── tailwind.config.js
├── postcss.config.js
├── eslint.config.js
├── .prettierrc
└── .gitignore
```

### 4.2 模块依赖关系

```
pages → hooks → stores → services → db
  ↓       ↓       ↓
components  utils / types
```

**依赖规则：**

- `types/` 和 `utils/` 不依赖任何业务模块
- `db/` 仅依赖 `types/`
- `services/` 依赖 `db/` + `types/` + `utils/`
- `stores/` 依赖 `services/`
- `hooks/` 依赖 `stores/`
- `pages/` 和 `components/` 依赖 `hooks/` + `stores/` + `utils/`
- **禁止** UI 层直接 import `db/`

### 4.3 关键文件说明

#### `src/db/index.ts` — 数据库定义

```typescript
import Dexie, { type Table } from 'dexie';
import type { Record, Category } from '@/types';

class ExpenseDB extends Dexie {
  records!: Table<Record>;
  categories!: Table<Category>;  // v1.0 启用

  constructor() {
    super('ExpenseTrackerDB');
    this.version(1).stores({
      records: 'id, date, type, [date+type]',
    });
    this.version(2).stores({       // v1.0 迁移
      records: 'id, date, type, category, [date+type]',
      categories: 'id, type, sort',
    });
  }
}

export const db = new ExpenseDB();
```

#### `src/services/recordService.ts` — 业务逻辑

```typescript
// 封装所有记录 CRUD，UI 层通过 store 调用
export const recordService = {
  create(data: CreateRecordInput): Promise<Record>,
  update(id: string, data: UpdateRecordInput): Promise<Record>,
  delete(id: string): Promise<void>,
  getById(id: string): Promise<Record | undefined>,
  getByMonth(year: number, month: number): Promise<Record[]>,
  getAll(): Promise<Record[]>,
};
```

#### `src/stores/recordStore.ts` — 状态管理

```typescript
// Zustand store：缓存当前月数据，避免重复查询
interface RecordStore {
  records: Record[];
  currentYear: number;
  currentMonth: number;
  isLoading: boolean;
  fetchRecords: (year: number, month: number) => Promise<void>;
  addRecord: (data: CreateRecordInput) => Promise<void>;
  updateRecord: (id: string, data: UpdateRecordInput) => Promise<void>;
  removeRecord: (id: string) => Promise<void>;
}
```

### 4.4 路由设计

| 路径 | 页面组件 | 阶段 | 说明 |
|------|----------|------|------|
| `/` | `HomePage` | MVP | 首页（统计 + 流水） |
| `/add` | `AddRecordPage` | MVP | 新增记录 |
| `/record/:id` | `RecordDetailPage` | MVP | 查看/编辑/删除 |
| `/stats` | `StatsPage` | v1.0 | 分类统计 |
| `/settings` | `SettingsPage` | v1.1 | 设置 |

```typescript
// src/App.tsx
const router = createBrowserRouter([
  {
    element: <AppLayout />,
    children: [
      { path: '/', element: <HomePage /> },
      { path: '/add', element: <AddRecordPage /> },
      { path: '/record/:id', element: <RecordDetailPage /> },
      // v1.0+
      { path: '/stats', element: <StatsPage /> },
      { path: '/settings', element: <SettingsPage /> },
    ],
  },
]);
```

---

## 5. 数据模型

### 5.1 实体关系图

```
MVP:

  ┌──────────────┐
  │    Record    │
  │──────────────│
  │ id (PK)      │
  │ type         │
  │ amount       │
  │ note         │
  │ date         │
  │ time         │
  │ createdAt    │
  │ updatedAt    │
  └──────────────┘

v1.0 新增:

  ┌──────────────┐         ┌──────────────┐
  │    Record    │         │   Category   │
  │──────────────│         │──────────────│
  │ id (PK)      │         │ id (PK)      │
  │ type         │         │ name         │
  │ amount       │         │ type         │
  │ category (FK)│────────►│ icon         │
  │ note         │         │ sort         │
  │ date         │         │ isDefault    │
  │ time         │         └──────────────┘
  │ createdAt    │
  │ updatedAt    │
  └──────────────┘

v2.0 新增:

  ┌──────────┐     ┌──────────────┐     ┌──────────────┐
  │   User   │     │    Record    │     │   Category   │
  │──────────│     │──────────────│     │──────────────│
  │ id (PK)  │◄────│ userId (FK)  │     │ userId (FK)  │
  │ email    │     │ syncStatus   │     │ ...          │
  │ password │     │ ...          │     └──────────────┘
  └──────────┘     └──────────────┘
```

### 5.2 Record（记账记录）

MVP 核心实体，存储每一条收入或支出。

```typescript
// src/types/record.ts

export type RecordType = 'income' | 'expense';

export interface Record {
  id: string;              // UUID，主键
  type: RecordType;          // 收入 | 支出
  amount: number;            // 金额（正数，最多 2 位小数）
  note: string;              // 备注（最长 100 字，默认 ""）
  date: string;              // 记账日期，格式 YYYY-MM-DD
  time: string;              // 记账时间，格式 HH:mm
  category?: string;         // 分类 ID（v1.0 可选）
  createdAt: string;         // 创建时间 ISO 8601
  updatedAt: string;         // 最后修改时间 ISO 8601
}

export interface CreateRecordInput {
  type: RecordType;
  amount: number;
  note?: string;
  date?: string;             // 默认今天
  time?: string;             // 默认当前时刻
  category?: string;
}

export interface UpdateRecordInput {
  type?: RecordType;
  amount?: number;
  note?: string;
  date?: string;
  time?: string;
  category?: string;
}
```

**IndexedDB 索引：**

| 索引名 | 字段 | 用途 |
|--------|------|------|
| `id` | `id` | 主键，按 ID 查单条 |
| `date` | `date` | 按日期范围查询（月度流水） |
| `type` | `type` | 按类型过滤 |
| `[date+type]` | 复合 | 按月 + 按类型统计 |

**约束与校验：**

| 字段 | 规则 |
|------|------|
| `amount` | > 0 且 ≤ 999,999.99，最多 2 位小数 |
| `note` | 最长 100 字符，超出截断 |
| `date` | 合法日期，不可为未来 |
| `type` | 仅 `income` 或 `expense` |

### 5.3 Category（分类，v1.0）

```typescript
// src/types/category.ts

export interface Category {
  id: string;                // 主键，如 "expense-food"
  name: string;              // 显示名称，如 "餐饮"
  type: RecordType;          // 适用类型
  icon: string;              // emoji 图标，如 "🍜"
  sort: number;              // 排序权重（越小越靠前）
  isDefault: boolean;        // true = 系统预设，不可删除
}
```

**预设数据（seed）：**

| id | name | type | icon | sort |
|----|------|------|------|------|
| expense-food | 餐饮 | expense | 🍜 | 1 |
| expense-transport | 交通 | expense | 🚇 | 2 |
| expense-shopping | 购物 | expense | 🛒 | 3 |
| expense-entertainment | 娱乐 | expense | 🎮 | 4 |
| expense-housing | 居住 | expense | 🏠 | 5 |
| expense-medical | 医疗 | expense | 💊 | 6 |
| expense-education | 教育 | expense | 📚 | 7 |
| expense-other | 其他 | expense | 📦 | 99 |
| income-salary | 工资 | income | 💰 | 1 |
| income-parttime | 兼职 | income | 💼 | 2 |
| income-investment | 理财 | income | 📈 | 3 |
| income-gift | 红包 | income | 🧧 | 4 |
| income-other | 其他 | income | 📦 | 99 |

### 5.4 统计模型（计算产物，不持久化）

```typescript
// src/types/stats.ts

export interface MonthlyStats {
  year: number;
  month: number;
  income: number;            // 收入合计
  expense: number;           // 支出合计
  balance: number;           // 结余 = income - expense
}

export interface DailyGroup {
  date: string;              // YYYY-MM-DD
  dayLabel: string;          // 如 "5月23日 周五"
  records: Record[];
  dayIncome: number;
  dayExpense: number;
}

export interface CategoryStats {   // v1.0
  categoryId: string;
  categoryName: string;
  icon: string;
  total: number;
  percentage: number;        // 占当月该类型总额的比例
  count: number;             // 记录条数
}
```

### 5.5 UI 状态（内存，不持久化）

```typescript
// src/stores/uiStore.ts

interface UIStore {
  currentYear: number;       // 当前查看的年份
  currentMonth: number;      // 当前查看的月份（1-12）
  toast: { message: string; type: 'success' | 'error' } | null;
  confirmDialog: { title: string; onConfirm: () => void } | null;
}
```

### 5.6 云端模型（v2.0，PostgreSQL）

```sql
-- users 表
CREATE TABLE users (
  id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  email       VARCHAR(255) UNIQUE NOT NULL,
  password    VARCHAR(255) NOT NULL,
  created_at  TIMESTAMPTZ NOT NULL DEFAULT NOW(),
  updated_at  TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

-- records 表（与本地 Record 结构对齐，增加 user_id）
CREATE TABLE records (
  id          UUID PRIMARY KEY,
  user_id     UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  type        VARCHAR(10) NOT NULL CHECK (type IN ('income', 'expense')),
  amount      DECIMAL(10, 2) NOT NULL CHECK (amount > 0),
  note        VARCHAR(100) DEFAULT '',
  date        DATE NOT NULL,
  time        TIME NOT NULL,
  category    VARCHAR(50),
  created_at  TIMESTAMPTZ NOT NULL,
  updated_at  TIMESTAMPTZ NOT NULL,
  deleted_at  TIMESTAMPTZ              -- 软删除，用于同步
);

CREATE INDEX idx_records_user_date ON records(user_id, date);

-- categories 表
CREATE TABLE categories (
  id          VARCHAR(50) PRIMARY KEY,
  user_id     UUID REFERENCES users(id) ON DELETE CASCADE,  -- NULL = 系统预设
  name        VARCHAR(50) NOT NULL,
  type        VARCHAR(10) NOT NULL,
  icon        VARCHAR(10) NOT NULL,
  sort        INT NOT NULL DEFAULT 0,
  is_default  BOOLEAN NOT NULL DEFAULT FALSE
);
```

### 5.7 数据量估算

| 数据 | 单条大小 | 1 年估算 | 5 年估算 |
|------|----------|----------|----------|
| Record | ~200 bytes | 200B × 365 × 3 ≈ 220KB | ~1.1MB |
| Category | ~100 bytes | 13 条 ≈ 1.3KB | 可忽略 |

IndexedDB 默认容量 ≥ 50MB，完全满足个人记账场景。

---

## 6. API 设计（v2.0）

> MVP 无 API。以下为 v2.0 云同步预留设计。

### 6.1 认证

| 方法 | 路径 | 说明 |
|------|------|------|
| POST | `/api/auth/register` | 邮箱注册 |
| POST | `/api/auth/login` | 登录，返回 JWT |
| POST | `/api/auth/send-code` | 发送邮箱验证码 |

### 6.2 记录 CRUD

| 方法 | 路径 | 说明 |
|------|------|------|
| GET | `/api/records?since={timestamp}` | 增量拉取（同步用） |
| POST | `/api/records` | 创建记录 |
| PUT | `/api/records/:id` | 更新记录 |
| DELETE | `/api/records/:id` | 软删除 |

### 6.3 同步策略

```
1. 本地操作 → 写入 IndexedDB + 加入 syncQueue
2. syncQueue 每条记录带 { action, record, timestamp }
3. 联网时批量上传 syncQueue → 服务端按 updatedAt 合并
4. 服务端返回其他设备的变更 → 合并到本地 IndexedDB
5. 冲突解决：updatedAt 更大的版本胜出
```

---

## 7. 关键技术点

### 7.1 IndexedDB 数据访问与性能

**难点**：IndexedDB 是异步 API，操作不当易导致 UI 卡顿或数据不一致。

**方案**：

```typescript
// 按月份范围查询，利用 date 索引
async function getRecordsByMonth(year: number, month: number) {
  const startDate = `${year}-${String(month).padStart(2, '0')}-01`;
  const endDate = `${year}-${String(month).padStart(2, '0')}-31`;

  return db.records
    .where('date')
    .between(startDate, endDate, true, true)
    .reverse()
        .sortBy('time');
}
```

**注意事项**：

- 所有 DB 操作必须 `async/await`，禁止同步阻塞
- 写入成功后才能提示用户「已保存」
- Dexie Schema 变更必须通过 `version()` 递增 + 迁移脚本
- 清除数据时使用 `db.delete()` 而非逐条删除

### 7.2 金额精度处理

**难点**：JavaScript 浮点数精度问题（`0.1 + 0.2 !== 0.3`）。

**方案**：

```typescript
// 存储：转为分（整数）或保留 2 位小数
function normalizeAmount(value: number): number {
  return Math.round(value * 100) / 100;
}

// 统计：累加时使用整数运算
function sumAmounts(records: Record[]): number {
  const totalCents = records.reduce(
    (sum, r) => sum + Math.round(r.amount * 100), 0
  );
  return totalCents / 100;
}

// 显示：千分位 + 2 位小数
function formatAmount(amount: number): string {
  return amount.toLocaleString('zh-CN', {
    minimumFractionDigits: 2,
    maximumFractionDigits: 2,
  });
}
```

**注意事项**：

- 输入层限制最多 2 位小数
- 禁止使用 `parseFloat` 直接做累加
- 显示层统一走 `formatAmount()`

### 7.3 月份切换与数据联动

**难点**：切换月份时需同步更新统计卡片 + 流水列表，且不可选未来月份。

**方案**：

```typescript
function useMonthNavigation() {
  const { currentYear, currentMonth, setMonth } = useUIStore();
  const { fetchRecords } = useRecordStore();

  const goToPrevMonth = () => { /* 月份 -1，跨年处理 */ };
  const goToNextMonth = () => {
    const now = new Date();
    // 不可超过当前月
    if (currentYear === now.getFullYear() && currentMonth >= now.getMonth() + 1) return;
    /* 月份 +1 */
  };

  // 月份变化 → 自动拉取该月数据
  useEffect(() => {
    fetchRecords(currentYear, currentMonth);
  }, [currentYear, currentMonth]);

  return { currentYear, currentMonth, goToPrevMonth, goToNextMonth };
}
```

**注意事项**：

- 跨年边界：`1月 - 1 → 12月(去年)`，`12月 + 1 → 1月(明年)`
- 未来月份禁用但允许查看（空状态），PRD 要求不可选择未来月份
- 统计和列表共用同一份数据源，避免不一致

### 7.4 流水列表按日分组

**难点**：记录按日期倒序分组，同一天内按时间倒序。

**方案**：

```typescript
function groupRecordsByDay(records: Record[]): DailyGroup[] {
  const groups = new Map<string, Record[]>();

  for (const record of records) {
    const existing = groups.get(record.date) || [];
    existing.push(record);
    groups.set(record.date, existing);
  }

  return Array.from(groups.entries())
    .sort(([a], [b]) => b.localeCompare(a))  // 日期倒序
    .map(([date, dayRecords]) => ({
      date,
      dayLabel: formatDayLabel(date),         // "5月23日 周五"
      records: dayRecords.sort((a, b) => b.time.localeCompare(a.time)),
      dayIncome: sumByType(dayRecords, 'income'),
      dayExpense: sumByType(dayRecords, 'expense'),
    }));
}
```

### 7.5 虚拟滚动（性能优化）

**难点**：当单月记录 > 200 条时，DOM 节点过多导致滚动卡顿。

**方案**：

- MVP 阶段记录量通常 < 100 条/月，直接渲染即可
- v1.x 若需优化，引入 `@tanstack/react-virtual` 或 `react-window`
- 触发阈值：单页 > 200 条时启用

### 7.6 表单输入体验

**难点**：金额输入需支持数字键盘、实时校验、自动聚焦。

**方案**：

```typescript
// 金额输入框
<input
  type="text"           // 不用 number，避免 spinner 和科学计数法
  inputMode="decimal"    // 移动端弹出数字键盘
  pattern="[0-9]*\.?[0-9]*"
  autoFocus              // 打开记一笔页自动聚焦
  placeholder="0.00"
  value={amount}
  onChange={handleAmountChange}
/>
```

**校验逻辑**：

```typescript
function validateAmount(value: string): string | null {
  if (!value || value === '0') return '请输入有效金额';
  const num = parseFloat(value);
  if (isNaN(num) || num <= 0) return '金额必须大于 0';
  if (num > 999999.99) return '金额不能超过 999,999.99';
  if (!/^\d+(\.\d{1,2})?$/.test(value)) return '最多两位小数';
  return null;
}
```

### 7.7 Schema 版本迁移

**难点**：v1.0 新增 Category 表、Record 加 category 字段，需平滑升级不丢数据。

**方案**：

```typescript
// src/db/index.ts
this.version(1).stores({
  records: 'id, date, type, [date+type]',
});

this.version(2).stores({
  records: 'id, date, type, category, [date+type]',
  categories: 'id, type, sort',
}).upgrade(async (tx) => {
  // 迁移逻辑：为旧记录补 category = undefined（已兼容）
  await seedDefaultCategories(tx);
});
```

**注意事项**：

- Dexie `version()` 号只能递增，不可修改旧版本定义
- 迁移脚本必须幂等（重复执行不出错）
- 迁移前自动备份（Dexie 内部处理）

### 7.8 XSS 防护

**难点**：用户输入的备注可能包含恶意 HTML。

**方案**：

- React 默认转义 JSX 中的文本内容，无需额外处理
- **禁止**使用 `dangerouslySetInnerHTML` 渲染用户输入
- CSV 导出时对特殊字符做转义

### 7.9 PWA 离线支持（v1.x）

**难点**：Service Worker 缓存策略需平衡离线可用与更新及时。

**方案**：

```typescript
// vite.config.ts
VitePWA({
  registerType: 'autoUpdate',
  workbox: {
    globPatterns: ['**/*.{js,css,html,ico,png,svg}'],
    // App Shell 缓存，API 不缓存（MVP 无 API）
  },
});
```

- 静态资源：`CacheFirst`（加载快）
- 数据：IndexedDB 天然离线，不依赖 Service Worker

### 7.10 云同步冲突解决（v2.0 预研）

**难点**：多设备同时编辑同一条记录。

**方案**：Last-Write-Wins（LWW）

```
每条记录带 updatedAt 时间戳
同步时比较 updatedAt：
  - 本地 > 云端 → 上传本地版本
  - 云端 > 本地 → 覆盖本地
  - 相等 → 跳过
```

**注意事项**：

- 删除操作用软删除（`deletedAt` 字段），确保同步能传播删除
- 同步队列持久化到 IndexedDB，防止刷新丢失未同步的操作

### 7.11 技术风险与应对

| 风险 | 影响 | 应对 |
|------|------|------|
| IndexedDB 被用户清除 | 数据丢失 | v1.2 CSV 导出；v2.0 云同步 |
| Safari IndexedDB 限制 | 存储失败 | 捕获异常 + 提示；降级 localStorage |
| 浮点精度误差 | 统计不准 | 整数分运算 |
| 大量记录性能下降 | 列表卡顿 | 按月查询 + 虚拟滚动 |
| Dexie Schema 迁移失败 | 升级崩溃 | 迁移前 try-catch + 版本回退 |

---

## 8. 部署方案

### 8.1 MVP 部署（Vercel）

```bash
# 构建
npm run build    # 输出到 dist/

# Vercel 自动检测 Vite 项目，零配置部署
# 或使用 CLI：
npx vercel --prod
```

**环境变量**：MVP 无后端，无需环境变量。

### 8.2 构建产物

```
dist/
├── index.html          # ~1KB
├── assets/
│   ├── index-xxx.js    # ~150KB (gzip ~50KB)
│   └── index-xxx.css   # ~10KB (gzip ~3KB)
└── icons/
```

目标：gzip 总量 ≤ 500KB（PRD 要求）。

### 8.3 CI/CD（可选）

```yaml
# .github/workflows/deploy.yml
name: Deploy
on:
  push:
    branches: [main]
jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: actions/setup-node@v4
        with: { node-version: 20 }
      - run: npm ci
      - run: npm run build
      - run: npx vercel --prod --token=${{ secrets.VERCEL_TOKEN }}
```

---

## 9. 开发规范

### 9.1 命名约定

| 类型 | 规范 | 示例 |
|------|------|------|
| 组件文件 | PascalCase | `StatCard.tsx` |
| 工具/服务 | camelCase | `recordService.ts` |
| 类型文件 | camelCase | `record.ts` |
| 常量 | UPPER_SNAKE | `MAX_AMOUNT` |
| CSS 类 | Tailwind 工具类 | `text-red-500` |

### 9.2 Git 分支

| 分支 | 用途 |
|------|------|
| `main` | 稳定发布版 |
| `dev` | 开发集成分支 |
| `feat/xxx` | 功能分支 |
| `fix/xxx` | 修复分支 |

### 9.3 提交信息

```
feat: 新增记一笔页面
fix: 修复月份切换跨年边界
refactor: 抽取统计计算到 statsService
docs: 更新技术设计文档
```

---

## 10. 版本演进计划

| 版本 | 技术变更 | 新增依赖 |
|------|----------|----------|
| **v0.1 MVP** | 纯前端 + IndexedDB | react, vite, tailwind, zustand, dexie, date-fns |
| **v1.0** | +分类 + Chart.js | chart.js |
| **v1.1** | +设置页 + 主题切换 | — |
| **v1.2** | +CSV 导出 + 搜索 | — |
| **v1.x** | +PWA 离线 | vite-plugin-pwa |
| **v2.0** | +后端 API + 云同步 | fastify, drizzle, pg, jsonwebtoken |

---

## 附录

### A. 技术选型对比记录

| 决策点 | 候选方案 | 最终选择 | 原因 |
|--------|----------|----------|------|
| 前端框架 | React / Vue / Svelte | React | 生态最大，PRD 推荐 |
| 状态管理 | Redux / Zustand / Jotai | Zustand | 最轻量，状态简单 |
| 本地存储 | localStorage / IndexedDB / sql.js | IndexedDB (Dexie) | 容量大、支持索引 |
| 后端框架 | Express / Fastify / FastAPI | Fastify (v2.0) | 性能好、TS 友好 |
| 云端数据库 | PostgreSQL / MySQL / MongoDB | PostgreSQL | 关系型、JSON 支持好 |
| 部署 | Vercel / Netlify / 自建 | Vercel | 零配置、免费 |

### B. 修订记录

| 版本 | 日期 | 修改内容 |
|------|------|----------|
| v1.0 | 2026-05-23 | 初稿，基于 PRD v1.0 编写 |

---

> **文档结束**  
> 下一步：搭建项目脚手架 → 实现 DB 层 + Service 层 → 开发 MVP 页面。
