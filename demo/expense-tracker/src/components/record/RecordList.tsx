import { statsService } from '@/services/statsService';
import type { Record } from '@/types/record';
import { RecordItem } from './RecordItem';

interface RecordListProps {
  records: Record[];
}

export function RecordList({ records }: RecordListProps) {
  const groups = statsService.groupByDay(records);

  return (
    <div className="space-y-4">
      {groups.map((group) => (
        <section key={group.date} className="space-y-2">
          <h2 className="px-1 text-sm font-medium text-text-secondary">{group.dayLabel}</h2>
          <div className="space-y-2">
            {group.records.map((record) => (
              <RecordItem key={record.id} record={record} />
            ))}
          </div>
        </section>
      ))}
    </div>
  );
}
