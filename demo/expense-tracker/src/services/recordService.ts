import api from './api';
import type { CreateRecordInput, Record, RecordType, UpdateRecordInput } from '@/types/record';
import type { MonthSummary } from '@/types/stats';

interface ApiRecord {
  id: string;
  type: RecordType;
  amount_yuan: number;
  note: string;
  category?: string | null;
  subcategory?: string | null;
  date: string;
  time?: string | null;
  image?: string | null;
  created_at: string;
  updated_at: string;
}

function toRecord(api: ApiRecord): Record {
  return {
    id: api.id,
    type: api.type,
    amount: api.amount_yuan,
    note: api.note,
    category: api.category ?? undefined,
    subcategory: api.subcategory ?? undefined,
    date: api.date,
    time: api.time ?? '',
    image: api.image ?? undefined,
    createdAt: api.created_at,
    updatedAt: api.updated_at,
  };
}

export interface MonthStats {
  total_income: number;
  total_expense: number;
  balance: number;
  count: number;
}

export const recordService = {
  async getByMonth(year: number, month: number): Promise<Record[]> {
    const res = await api.get("/records/", { params: { year, month } });
    return res.data.results.map(toRecord);
  },

  async create(data: CreateRecordInput, image?: File): Promise<Record> {
    const formData = new FormData();
    formData.append("type", data.type);
    formData.append("amount_yuan", String(data.amount));
    formData.append("note", data.note ?? "");
    formData.append("date", data.date ?? new Date().toISOString().slice(0, 10));
    if (data.category) formData.append("category", data.category);
    if (data.subcategory) formData.append("subcategory", data.subcategory);
    if (data.time) formData.append("time", data.time);
    if (image) formData.append("image", image);

    const res = await api.post("/records/", formData, {
      headers: { "Content-Type": "multipart/form-data" },
    });
    return toRecord(res.data);
  },

  async update(id: string, data: UpdateRecordInput, image?: File): Promise<Record> {
    const formData = new FormData();
    if (data.type) formData.append("type", data.type);
    if (data.amount) formData.append("amount_yuan", String(data.amount));
    if (data.note !== undefined) formData.append("note", data.note ?? "");
    if (data.category !== undefined) formData.append("category", data.category ?? "");
    if (data.subcategory !== undefined) formData.append("subcategory", data.subcategory ?? "");
    if (data.date) formData.append("date", data.date);
    if (data.time !== undefined) formData.append("time", data.time ?? "");
    if (image) formData.append("image", image);

    const res = await api.patch("/records/" + id + "/", formData, {
      headers: { "Content-Type": "multipart/form-data" },
    });
    return toRecord(res.data);
  },

  async remove(id: string): Promise<void> {
    await api.delete("/records/" + id + "/");
  },

  async getById(id: string): Promise<Record | undefined> {
    const res = await api.get("/records/" + id + "/");
    return toRecord(res.data);
  },

  async getStats(year: number, month: number): Promise<MonthStats> {
    const res = await api.get("/records/stats/", { params: { year, month } });
    return res.data;
  },

  async getDates(year: number, month: number): Promise<string[]> {
    const res = await api.get("/records/dates/", { params: { year, month } });
    return res.data;
  },

  async getMonthSummaries(): Promise<MonthSummary[]> {
    const res = await api.get("/records/month_summaries/");
    return res.data;
  },
};
