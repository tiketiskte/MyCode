import Dexie, { type Table } from 'dexie';
import type { Record } from '@/types/record';

class ExpenseDB extends Dexie {
  records!: Table<Record>;

  constructor() {
    super('ExpenseTrackerDB');
    this.version(1).stores({
      records: 'id, date, type, [date+type]',
    });
  }
}

export const db = new ExpenseDB();
