# 简记 — 项目文档

个人轻量记账应用「简记」的设计与开发文档。

## 文档索引

| 文档 | 说明 |
|------|------|
| [PRD.md](./PRD.md) | 产品需求：功能、优先级、UI 规范 |
| [tech-design.md](./tech-design.md) | 技术设计：架构、数据模型、关键技术 |
| [agents.md](./agents.md) | 开发指令：规范、约束、开发顺序 |

**阅读顺序**：PRD → tech-design → agents

---

## 项目目录结构

```
expense-tracker/
├── docs/                    # 📄 文档（你在这里）
│   ├── README.md
│   ├── PRD.md
│   ├── tech-design.md
│   └── agents.md
│
├── public/                  # 静态资源
│   └── favicon.svg
│
├── src/                     # 💻 源代码
│   ├── app/                 # 应用入口 & 路由
│   ├── pages/               # 页面（与路由一一对应）
│   ├── components/          # UI 组件
│   │   ├── layout/          # 布局
│   │   ├── record/          # 记账业务组件
│   │   └── ui/              # 通用 UI 原子组件
│   ├── hooks/               # 自定义 Hooks
│   ├── stores/              # Zustand 状态
│   ├── services/            # 业务逻辑
│   ├── db/                  # IndexedDB（Dexie）
│   ├── types/               # TypeScript 类型
│   ├── utils/               # 工具函数
│   ├── styles/              # 全局样式
│   ├── main.tsx             # 启动入口
│   └── vite-env.d.ts
│
├── AGENTS.md                # Cursor Agent 快速入口
├── index.html
├── package.json
├── vite.config.ts
├── tailwind.config.js
├── tsconfig.json
└── eslint.config.js
```

## 当前阶段

**MVP（v0.1）** — 记一笔、月度统计、流水列表、编辑删除、IndexedDB 本地存储。
