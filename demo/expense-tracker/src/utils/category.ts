import type { RecordType } from '@/types/record';
import { RECORD_CATEGORIES } from './constants';

export function getRecordCategory(type: RecordType, categoryId?: string) {
  const categories = RECORD_CATEGORIES[type];
  return categories.find((item) => item.id === categoryId) ?? categories[categories.length - 1];
}

export function getRecordSubcategory(
  type: RecordType,
  categoryId?: string,
  subcategoryId?: string,
) {
  const category = getRecordCategory(type, categoryId);
  return category.children.find((item) => item.id === subcategoryId) ?? category.children[0];
}
