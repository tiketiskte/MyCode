# 简记 — AI 开发指令

| 项目 | 内容 |
|------|------|
| **版本** | v1.0 |
| **关联** | [PRD.md](./PRD.md) · [tech-design.md](./tech-design.md) |
| **适用** | MVP（v0.1）开发 |

---

## 目录

1. [项目概述](#1-项目概述)
2. [MVP 范围](#2-mvp-范围)
3. [技术栈](#3-技术栈)
4. [项目结构](#4-项目结构)
5. [架构与分层](#5-架构与分层)
6. [数据模型](#6-数据模型)
7. [UI 与设计规范](#7-ui-与设计规范)
8. [开发规范](#8-开发规范)
9. [关键技术约束](#9-关键技术约束)
10. [MVP 开发顺序](#10-mvp-开发顺序)
11. [验收标准](#11-验收标准)
12. [禁止事项](#12-禁止事项)
13. [测试要求](#13-测试要求)

---

## 1. 项目概述

**简记**是一款轻量个人记账 Web 应用。

- **核心价值**：3 秒内记一笔，快速查看当月收支
- **产品原则**：够用就好，极简，零注册，本地优先
- **当前阶段**：MVP（v0.1），4 周内交付

一句话：**打开即记，记完即走，每月心中有数。**

---

## 2. MVP 范围

### 2.1 必须实现（P0）

| 编号 | 功能 | 说明 |
|------|------|------|
| F01 | 快捷记一笔 | 类型（收入/支出）+ 金额 + 可选备注 |
| F02 | 当月统计 | 收入、支出、结余三数卡片 |
| F03 | 月份切换 | 左右箭头，不可选未来月份 |
| F04 | 流水列表 | 按日分组，日期/时间倒序 |
| F05 | 编辑/删除 | 单条 CRUD，删除需二次确认 |
| F06 | 本地存储 | IndexedDB（Dexie.js），刷新不丢失 |

### 2.2 明确不做

- 用户登录 / 注册
- 分类体系（v1.0）
- 图表 / 统计分析（v1.0+）
- CSV 导出（v1.2）
- 云同步 / 后端 API（v2.0）
- 多账本、预算、搜索、PWA

> 若用户未明确要求，**不要**提前实现上述功能。

### 2.3 页面与路由

| 路由 | 页面 | 职责 |
|------|------|------|
| `/` | HomePage | 统计卡片 + 月份切换 + 流水列表 + 浮动「+」 |
| `/add` | AddRecordPage | 新增记录，金额输入框 autoFocus |
| `/record/:id` | RecordDetailPage | 查看 / 编辑 / 删除 |

---

## 3. 技术栈

### 3.1 MVP 使用

| 类别 | 选型 | 备注 |
|------|------|------|
| 框架 | React 18 + TypeScript 5 | 函数组件 + Hooks |
| 构建 | Vite 5 | |
| 样式 | Tailwind CSS 3 | 遵循 PRD 色彩规范 |
| 状态 | Zustand 4 | 不用 Redux |
| 路由 | React Router 6 | |
| 本地数据库 | **Dexie.js 4（IndexedDB）** | **不用 localStorage** |
| 日期 | date-fns 3 | |
| ID | `crypto.randomUUID()` | 不用第三方 UUID 库 |
| 规范 | ESLint + Prettier | |

### 3.2 MVP 不使用

- 后端、API、PostgreSQL
- Redux、MobX
- UI 组件库（Ant Design / MUI）— 保持轻量，自写小组件
- localStorage 存记录数据

---

## 4. 项目结构

```
expense-tracker/
├── docs/
│   ├── README.md
│   ├── PRD.md
│   ├── tech-design.md
│   └── agents.md              ← 本文档
├── public/
│   └── favicon.svg
├── src/
│   ├── app/                   # App.tsx + router.tsx
│   ├── pages/                 # 页面，对接路由
│   │   ├── HomePage.tsx
│   │   ├── AddRecordPage.tsx
│   │   └── RecordDetailPage.tsx
│   ├── components/
│   │   ├── layout/            # AppLayout, PageHeader
│   │   ├── record/            # StatCard, MonthPicker, RecordList, ...
│   │   └── ui/                # Button, Input, Toast, ConfirmDialog
│   ├── hooks/                 # useRecords, useMonthlyStats, useMonthNavigation
│   ├── stores/                # recordStore, uiStore
│   ├── services/              # recordService, statsService
│   ├── db/                    # Dexie 实例
│   ├── types/                 # record.ts, stats.ts
│   ├── utils/                 # format, validate, date, constants
│   ├── styles/                # global.css
│   ├── main.tsx
│   └── vite-env.d.ts
├── AGENTS.md                  # Agent 入口摘要
├── index.html
├── package.json
├── vite.config.ts
└── tailwind.config.js
```

新增文件时放入对应目录，**不要**扁平堆在 `src/` 根下。

---

## 5. 架构与分层

### 5.1 依赖方向

```
pages / components
       ↓
     hooks
       ↓
     stores
       ↓
    services
       ↓
       db
       ↓
  types / utils（被各层引用，不依赖业务）
```

### 5.2 各层职责

| 层级 | 职责 | 禁止 |
|------|------|------|
| **pages** | 组合组件、对接路由 | 不写 DB 查询、不写统计公式 |
| **components** | 展示 + 事件回调 | 不直接 import `db/` |
| **hooks** | 连接 store 与组件 | 不绕过 store 直接调 service |
| **stores** | 全局状态、触发 service | 不写 UI 逻辑 |
| **services** | CRUD、统计、校验 | 不操作 React 状态 |
| **db** | Dexie 表定义、索引 | 不含业务规则 |

### 5.3 代码示例

```typescript
// ❌ 错误：组件直接访问数据库
function RecordList() {
  useEffect(() => {
    db.records.toArray().then(setRecords);
  }, []);
}

// ✅ 正确：通过 store
function RecordList() {
  const { records, fetchRecords } = useRecordStore();
  const { currentYear, currentMonth } = useUIStore();
  useEffect(() => {
    fetchRecords(currentYear, currentMonth);
  }, [currentYear, currentMonth]);
}
```

```typescript
// ❌ 错误：浮点累加
const total = records.reduce((s, r) => s + r.amount, 0);

// ✅ 正确：整数分运算
const total = records.reduce((s, r) => s + Math.round(r.amount * 100), 0) / 100;
```

---

## 6. 数据模型

### 6.1 Record（核心实体）

```typescript
export type RecordType = 'income' | 'expense';

export interface Record {
  id: string;           // UUID
  type: RecordType;
  amount: number;       // 正数，最多 2 位小数
  note: string;         // 默认 ""，最长 100 字
  date: string;         // YYYY-MM-DD
  time: string;         // HH:mm
  createdAt: string;    // ISO 8601
  updatedAt: string;
}
```

### 6.2 校验规则

| 字段 | 规则 |
|------|------|
| `amount` | > 0 且 ≤ 999,999.99，最多 2 位小数 |
| `note` | 最长 100 字符，超出截断 |
| `date` | 合法日期，不可为未来 |
| `type` | 仅 `income` 或 `expense` |

### 6.3 IndexedDB 索引

```typescript
this.version(1).stores({
  records: 'id, date, type, [date+type]',
});
```

### 6.4 统计（不持久化，由 statsService 计算）

```typescript
interface MonthlyStats {
  income: number;
  expense: number;
  balance: number;  // income - expense
}
```

---

## 7. UI 与设计规范

### 7.1 色彩（Tailwind 或 CSS 变量）

| 用途 | 色值 |
|------|------|
| 主色 | `#2563EB` |
| 收入 | `#16A34A` |
| 支出 | `#DC2626` |
| 背景 | `#F9FAFB` |
| 卡片 | `#FFFFFF` |
| 文字主色 | `#111827` |
| 文字辅色 | `#6B7280` |

### 7.2 布局

- 移动端优先，桌面居中限宽 **420px**
- 页面边距 16px，卡片圆角 12px
- 列表项高度 ≥ 56px
- 首页底部浮动「+」按钮

### 7.3 交互

| 操作 | 行为 |
|------|------|
| 打开记一笔 | 金额输入框 `autoFocus`，`inputMode="decimal"` |
| 保存成功 | Toast「已保存」→ 返回首页 |
| 删除 | ConfirmDialog 二次确认 |
| 无备注 | 显示「未命名」 |
| 本月无记录 | EmptyState + 引导按钮 |

### 7.4 金额显示

- 千分位 + 2 位小数：`12,345.67`
- 收入前缀 `+`，支出前缀 `-`
- 统一走 `formatAmount()`，不在组件内重复格式化

---

## 8. 开发规范

### 8.1 代码风格

| 类型 | 规范 | 示例 |
|------|------|------|
| 组件文件 | PascalCase | `StatCard.tsx` |
| 工具/服务 | camelCase | `recordService.ts` |
| 组件名 | PascalCase | `RecordList` |
| 函数/变量 | camelCase | `fetchRecords` |
| 常量 | UPPER_SNAKE | `MAX_AMOUNT` |
| 类型/接口 | PascalCase | `MonthlyStats` |

### 8.2 组件规范

- 只用函数组件 + Hooks
- 可复用逻辑抽到 `hooks/`
- Props 用 TypeScript 接口定义
- 禁止 `dangerouslySetInnerHTML` 渲染用户输入（备注）

### 8.3 文件组织

- 一个组件一个文件
- 页面专属组件放 `components/record/`，通用组件放 `components/ui/`
- 类型定义放 `types/`，不在组件文件内重复定义

### 8.4 Git 提交

```
feat: 新增记一笔页面
fix: 修复月份切换跨年边界
refactor: 抽取统计计算到 statsService
```

分支：`main`（稳定）、`dev`（开发）、`feat/xxx`（功能）

---

## 9. 关键技术约束

### 9.1 IndexedDB

- 所有 DB 操作 `async/await`，禁止同步阻塞
- **写入成功后**才 Toast「已保存」
- 按月查询用 `date` 索引：`where('date').between(start, end)`
- Schema 变更通过 Dexie `version()` 递增

### 9.2 金额精度

```typescript
function normalizeAmount(value: number): number {
  return Math.round(value * 100) / 100;
}
```

- 输入层限制 2 位小数
- 统计层用整数分累加
- 显示层用 `toLocaleString('zh-CN')`

### 9.3 月份切换

- 跨年：`1月-1 → 12月(去年)`，`12月+1 → 1月(明年)`
- 不可切换到未来月份
- 切换后 `fetchRecords(year, month)` 刷新统计和列表

### 9.4 流水分组

- 按 `date` 倒序分组
- 组内按 `time` 倒序
- 分组逻辑放 `utils/date.ts` 或 `statsService`

### 9.5 性能

- MVP 单月记录通常 < 100 条，直接渲染即可
- 路由懒加载非首屏页面（可选）
- 首屏 gzip ≤ 500KB

---

## 10. MVP 开发顺序

按以下顺序实施，每步完成后可独立验证：

```
Step 1  项目脚手架
        Vite + React + TS + Tailwind + 路径别名 @/

Step 2  数据层
        types/record.ts → db/index.ts → services/recordService.ts

Step 3  状态层
        stores/recordStore.ts + stores/uiStore.ts

Step 4  工具层
        utils/format.ts + utils/validate.ts + utils/date.ts

Step 5  通用 UI
        components/ui/（Button, Input, Toast, ConfirmDialog）

Step 6  首页
        StatCard + MonthPicker + RecordList + EmptyState + HomePage

Step 7  记一笔
        RecordForm + AddRecordPage

Step 8  详情页
        RecordDetailPage（查看/编辑/删除）

Step 9  联调与 polish
        响应式、空状态、错误提示、跨月边界
```

**不要跳步**：先打通 `db → service → store` 数据链路，再写 UI。

---

## 11. 验收标准

### 11.1 功能验收

| # | 场景 | 通过标准 |
|---|------|----------|
| 1 | 新增支出 | 支出 50 → 首页支出 +50 |
| 2 | 新增收入 | 收入 3000 → 首页收入 +3000 |
| 3 | 结余 | 收入 3000、支出 500 → 结余 2500 |
| 4 | 备注 | 备注「午餐」→ 流水显示「午餐」 |
| 5 | 月份切换 | 切到上月 → 统计和流水同步更新 |
| 6 | 编辑 | 金额 50→80 → 统计同步 |
| 7 | 删除 | 删除一条 → 统计减少 |
| 8 | 持久化 | 刷新页面 → 数据仍在 |
| 9 | 空状态 | 无记录月份 → 显示引导 |
| 10 | 校验 | 金额空或 0 → 无法保存，有提示 |
| 11 | 响应式 | 320px 宽度布局正常 |
| 12 | 性能 | 首屏 < 2 秒 |

### 11.2 体验验收

- 记一笔（不含备注）≤ 3 步
- 删除有二次确认
- 金额显示千分位 + 2 位小数

---

## 12. 禁止事项

| 禁止 | 原因 |
|------|------|
| UI 直接 import `db/` | 破坏分层 |
| 用 localStorage 存记录 | tech-design 已定 IndexedDB |
| MVP 实现登录/分类/图表 | 超出 MVP 范围 |
| 引入重型 UI 库 | 违背极简原则 |
| 浮点直接累加金额 | 精度误差 |
| 写入前提示「已保存」 | 可能丢数据 |
| `dangerouslySetInnerHTML` | XSS 风险 |
| 过度抽象（不必要的 wrapper） | 违背简单优先 |
| 未请求就写 README / 测试框架 | 用户未要求则不添加 |

---

## 13. 测试要求

### 13.1 MVP 阶段

- **手动测试**为主，每个 Step 完成后按 §11 验收
- 不强制单元测试框架，除非用户明确要求

### 13.2 必测边界

| 场景 | 预期 |
|------|------|
| 金额 0 / 空 / 负数 | 拒绝保存，显示错误 |
| 金额 999999.99 | 正常保存 |
| 金额 1000000 | 拒绝保存 |
| 备注超 100 字 | 截断 |
| 跨年切换月份 | 年月正确 |
| 切换到当前月之后的月份 | 禁止或无效 |
| 删除最后一条记录 | 统计归零，显示空状态 |
| 刷新 / 关闭重开 | 数据完整 |
| 快速连续保存多条 | 不丢记录、不重复 |

### 13.3 移动端

- 金额输入弹出数字键盘（`inputMode="decimal"`）
- 触摸滚动流畅
- 浮动按钮不被遮挡

---

## 附录：服务层接口约定

```typescript
// services/recordService.ts
export const recordService = {
  create(data: CreateRecordInput): Promise<Record>;
  update(id: string, data: UpdateRecordInput): Promise<Record>;
  delete(id: string): Promise<void>;
  getById(id: string): Promise<Record | undefined>;
  getByMonth(year: number, month: number): Promise<Record[]>;
};

// services/statsService.ts
export const statsService = {
  getMonthlyStats(records: Record[]): MonthlyStats;
  groupByDay(records: Record[]): DailyGroup[];
};
```

详细设计见 [tech-design.md](./tech-design.md)。

---

> **执行原则**：先读 PRD 确认范围 → 按本文档顺序开发 → 完成一步验收一步 → 保持简洁，不做 PRD 以外的事。
