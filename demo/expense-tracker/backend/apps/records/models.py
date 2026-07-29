from django.contrib.auth.models import User
from django.db import models


class Record(models.Model):
    class RecordType(models.TextChoices):
        INCOME = "income", "收入"
        EXPENSE = "expense", "支出"

    user = models.ForeignKey(
        User, on_delete=models.CASCADE, related_name="records"
    )
    type = models.CharField("类型", max_length=10, choices=RecordType.choices)
    amount = models.IntegerField("金额（分）")  # 整数分，避免浮点精度问题
    note = models.CharField("备注", max_length=200, blank=True, default="")
    category = models.CharField("分类", max_length=50, blank=True, null=True)
    subcategory = models.CharField("子分类", max_length=50, blank=True, null=True)
    date = models.DateField("日期")
    time = models.TimeField("时间", blank=True, null=True)
    image = models.ImageField("图片", upload_to="receipts/", blank=True, null=True)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        verbose_name = "记账记录"
        verbose_name_plural = "记账记录"
        ordering = ["-date", "-time"]

    def __str__(self):
        return f"{self.get_type_display()} {self.amount / 100:.2f} - {self.date}"
