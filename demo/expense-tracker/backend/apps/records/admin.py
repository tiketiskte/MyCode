from django.contrib import admin
from .models import Record

@admin.register(Record)
class RecordAdmin(admin.ModelAdmin):
    list_display = ["user", "type", "amount", "note", "date"]
    list_filter = ["type", "date", "user"]
    search_fields = ["note", "user__username"]
    date_hierarchy = "date"
