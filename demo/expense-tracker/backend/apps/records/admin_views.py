from rest_framework import status
from rest_framework.decorators import api_view, permission_classes
from rest_framework.permissions import IsAdminUser
from rest_framework.response import Response
from django.contrib.auth.models import User
from django.db.models import Sum, Count
from django.http import HttpResponse
import csv
from collections import defaultdict

from apps.records.models import Record
from apps.accounts.serializers import UserSerializer
from apps.records.serializers import RecordSerializer


@api_view(["GET"])
@permission_classes([IsAdminUser])
def list_users(request):
    users = User.objects.all().order_by("username")
    return Response(UserSerializer(users, many=True).data)


@api_view(["GET"])
@permission_classes([IsAdminUser])
def all_records(request):
    qs = Record.objects.all().select_related("user").order_by("-date", "-time")
    user_id = request.query_params.get("user_id")
    if user_id:
        qs = qs.filter(user_id=user_id)
    year = request.query_params.get("year")
    month = request.query_params.get("month")
    if year:
        qs = qs.filter(date__year=year)
    if month:
        qs = qs.filter(date__month=month)
    data = [{"id": str(r.id), "type": r.type, "amount_yuan": r.amount / 100.0, "note": r.note, "category": r.category, "date": str(r.date), "user": r.user.username} for r in qs]; return Response(data)
    return Response(serializer.data)


@api_view(["GET"])
@permission_classes([IsAdminUser])
def category_stats(request):
    year = request.query_params.get("year")
    month = request.query_params.get("month")
    user_id = request.query_params.get("user_id")

    qs = Record.objects.all()
    if year:
        qs = qs.filter(date__year=year)
    if month:
        qs = qs.filter(date__month=month)
    if user_id:
        qs = qs.filter(user_id=user_id)

    # 按分类统计
    expense_cats = (
        qs.filter(type=Record.RecordType.EXPENSE)
        .values("category")
        .annotate(total=Sum("amount"), count=Count("id"))
        .order_by("-total")
    )
    income_cats = (
        qs.filter(type=Record.RecordType.INCOME)
        .values("category")
        .annotate(total=Sum("amount"), count=Count("id"))
        .order_by("-total")
    )

    def fmt(cat):
        return {
            "category": cat["category"] or "未分类",
            "amount": cat["total"] / 100.0,
            "count": cat["count"],
        }

    return Response({
        "expense": [fmt(c) for c in expense_cats],
        "income": [fmt(c) for c in income_cats],
    })


@api_view(["GET"])
@permission_classes([IsAdminUser])
def monthly_trends(request):
    year = request.query_params.get("year")
    user_id = request.query_params.get("user_id")

    qs = Record.objects.all()
    if year:
        qs = qs.filter(date__year=year)
    else:
        import datetime
        qs = qs.filter(date__year=datetime.date.today().year)
    if user_id:
        qs = qs.filter(user_id=user_id)

    # 按月统计
    months = defaultdict(lambda: {"income": 0, "expense": 0, "count": 0})
    for r in qs:
        key = r.date.strftime("%Y-%m")
        months[key]["month"] = r.date.month
        if r.type == Record.RecordType.INCOME:
            months[key]["income"] += r.amount
        else:
            months[key]["expense"] += r.amount
        months[key]["count"] += 1

    result = []
    for key in sorted(months.keys()):
        m = months[key]
        result.append({
            "month": key,
            "income": round(m["income"] / 100.0, 2),
            "expense": round(m["expense"] / 100.0, 2),
            "count": m["count"],
        })
    return Response(result)


@api_view(["GET"])
@permission_classes([IsAdminUser])
def export_csv(request):
    qs = Record.objects.all().select_related("user").order_by("-date", "-time")
    user_id = request.query_params.get("user_id")
    if user_id:
        qs = qs.filter(user_id=user_id)

    response = HttpResponse(content_type="text/csv; charset=utf-8-sig")
    response["Content-Disposition"] = "attachment; filename=records_export.csv"

    writer = csv.writer(response)
    writer.writerow(["用户", "类型", "金额(元)", "分类", "子分类", "备注", "日期", "时间", "图片"])
    for r in qs:
        writer.writerow([
            r.user.username,
            r.get_type_display(),
            r.amount / 100.0,
            r.category or "",
            r.subcategory or "",
            r.note,
            r.date,
            r.time or "",
            r.image.url if r.image else "",
        ])
    return response

