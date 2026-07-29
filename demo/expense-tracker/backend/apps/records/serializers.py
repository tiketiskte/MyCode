from rest_framework import serializers
from .models import Record


class RecordSerializer(serializers.ModelSerializer):
    amount_yuan = serializers.DecimalField(
        max_digits=12,
        decimal_places=2,
        source="amount",
        help_text="金额（元）",
    )

    class Meta:
        model = Record
        fields = [
            "id",
            "type",
            "amount_yuan",
            "note",
            "category",
            "subcategory",
            "date",
            "time",
            "image",
            "created_at",
            "updated_at",
        ]
        read_only_fields = ["id", "created_at", "updated_at", "image"]

    def validate_amount_yuan(self, value):
        """将元转换为分存储"""
        return int(round(float(value) * 100))

    def to_representation(self, instance):
        data = super().to_representation(instance)
        data["amount_yuan"] = round(float(data["amount_yuan"]) / 100, 2)
        if data.get("image"):
            request = self.context.get("request")
            if request:
                data["image"] = request.build_absolute_uri(data["image"])
        return data


class RecordListSerializer(serializers.ModelSerializer):
    amount_yuan = serializers.SerializerMethodField()

    class Meta:
        model = Record
        fields = [
            "id",
            "type",
            "amount_yuan",
            "note",
            "category",
            "date",
            "image",
        ]

    def get_amount_yuan(self, obj):
        return obj.amount / 100.0
