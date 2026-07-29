from django.db.models import Sum, Q
from collections import defaultdict
from rest_framework import status, viewsets
from rest_framework.decorators import action
from rest_framework.parsers import JSONParser, FormParser, MultiPartParser
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response

from .models import Record
from .permissions import IsOwner
from .serializers import RecordListSerializer, RecordSerializer


class RecordViewSet(viewsets.ModelViewSet):
    parser_classes = [JSONParser, MultiPartParser, FormParser]
    permission_classes = [IsAuthenticated, IsOwner]

    def get_serializer_class(self):
        if self.action == "list":
            return RecordListSerializer
        return RecordSerializer

    def get_queryset(self):
        qs = Record.objects.filter(user=self.request.user)
        year = self.request.query_params.get("year")
        month = self.request.query_params.get("month")
        if year and month:
            qs = qs.filter(date__year=year, date__month=month)
        return qs

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

    @action(detail=False, methods=["get"])
    def stats(self, request):
        year = request.query_params.get("year")
        month = request.query_params.get("month")
        if not year or not month:
            return Response({"error": "需要 year 和 month 参数"}, status=400)

        qs = Record.objects.filter(
            user=request.user, date__year=year, date__month=month
        )
        total_income = (
            qs.filter(type=Record.RecordType.INCOME).aggregate(s=Sum("amount"))["s"] or 0
        )
        total_expense = (
            qs.filter(type=Record.RecordType.EXPENSE).aggregate(s=Sum("amount"))["s"] or 0
        )
        count = qs.count()

        return Response(
            {
                "total_income": total_income / 100.0,
                "total_expense": total_expense / 100.0,
                "balance": (total_income - total_expense) / 100.0,
                "count": count,
            }
        )

    @action(detail=False, methods=["get"])
    def dates(self, request):
        year = request.query_params.get("year")
        month = request.query_params.get("month")
        if not year or not month:
            return Response({"error": "需要 year 和 month 参数"}, status=400)
        dates = (
            Record.objects.filter(
                user=request.user, date__year=year, date__month=month
            )
            .values_list("date", flat=True)
            .distinct()
        )
        return Response([str(d) for d in dates])

    @action(detail=False, methods=["get"])
    def month_summaries(self, request):
        records = Record.objects.filter(user=request.user).order_by("-date")
        months = defaultdict(lambda: {"income": 0, "expense": 0, "count": 0})
        for r in records:
            key = r.date.strftime("%Y-%m")
            months[key]["month"] = r.date.month
            months[key]["year"] = r.date.year
            months[key]["count"] += 1
            if r.type == Record.RecordType.INCOME:
                months[key]["income"] += r.amount
            else:
                months[key]["expense"] += r.amount

        result = []
        for key in sorted(months.keys(), reverse=True):
            m = months[key]
            result.append(
                {
                    "monthKey": key,
                    "year": m["year"],
                    "month": m["month"],
                    "label": f'{m["year"]}' + "年" + f'{m["month"]}' + "月",
                    "income": m["income"] / 100.0,
                    "expense": m["expense"] / 100.0,
                    "balance": (m["income"] - m["expense"]) / 100.0,
                    "count": m["count"],
                }
            )
        return Response(result)
