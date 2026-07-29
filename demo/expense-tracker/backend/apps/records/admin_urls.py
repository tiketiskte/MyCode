from django.urls import path
from . import admin_views

urlpatterns = [
    path("users/", admin_views.list_users, name="admin-users"),
    path("records/", admin_views.all_records, name="admin-records"),
    path("stats/category/", admin_views.category_stats, name="admin-stats-category"),
    path("stats/monthly/", admin_views.monthly_trends, name="admin-stats-monthly"),
    path("export/", admin_views.export_csv, name="admin-export"),
]
