# 简记 — Agent 指令

> 完整开发规范见 **[docs/agents.md](./docs/agents.md)**  
> 产品需求见 [docs/PRD.md](./docs/PRD.md) · 技术设计见 [docs/tech-design.md](./docs/tech-design.md)

## 快速上下文

- **产品**：极简个人记账，3 秒记一笔，看月度收支
- **阶段**：MVP（v0.1），纯前端，无后端
- **栈**：React 18 + TypeScript + Vite + Tailwind + Zustand + Dexie.js
- **存储**：IndexedDB（Dexie），**禁止**用 localStorage 存记录

## 硬性约束

1. 分层：`pages/components → hooks → stores → services → db`，UI **禁止**直接访问 `db/`
2. MVP **不做**：登录、分类、图表、导出、云同步
3. 金额用整数分运算，禁止浮点累加
4. IndexedDB 写入成功后才提示「已保存」
5. 保持极简，不过度设计

## MVP 功能（P0）

| 功能 | 路由 |
|------|------|
| 首页（统计 + 流水） | `/` |
| 记一笔 | `/add` |
| 记录详情/编辑/删除 | `/record/:id` |

开发顺序与验收清单 → [docs/agents.md](./docs/agents.md)
