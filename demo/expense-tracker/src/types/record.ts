export type RecordType = 'income' | 'expense';

export interface Record {
  id: string;
  type: RecordType;
  amount: number;
  note: string;
  category?: string;
  subcategory?: string;
  image?: string;
  date: string;
  time: string;
  createdAt: string;
  updatedAt: string;
}

export interface CreateRecordInput {
  type: RecordType;
  amount: number;
  note?: string;
  category?: string;
  subcategory?: string;
  date?: string;
  time?: string;
}

export interface UpdateRecordInput {
  type?: RecordType;
  amount?: number;
  note?: string;
  category?: string;
  subcategory?: string;
  date?: string;
  time?: string;
}
