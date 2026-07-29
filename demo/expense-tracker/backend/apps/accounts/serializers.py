from django.contrib.auth.models import User
from rest_framework import serializers
from .models import UserProfile


class UserProfileSerializer(serializers.ModelSerializer):
    class Meta:
        model = UserProfile
        fields = ["display_name", "avatar"]


class UserSerializer(serializers.ModelSerializer):
    profile = serializers.SerializerMethodField()

    class Meta:
        model = User
        fields = ["id", "username", "profile", "is_superuser"]

    def get_profile(self, obj):
        data = UserProfileSerializer(obj.profile).data
        request = self.context.get("request")
        if data.get("avatar") and request:
            data["avatar"] = request.build_absolute_uri(data["avatar"])
        return data


class RegisterSerializer(serializers.ModelSerializer):
    password = serializers.CharField(write_only=True, min_length=4)
    display_name = serializers.CharField(max_length=32, required=False)

    class Meta:
        model = User
        fields = ["username", "password", "display_name"]

    def create(self, validated_data):
        display_name = validated_data.pop("display_name", None)
        user = User.objects.create_user(**validated_data)
        if display_name:
            user.profile.display_name = display_name
            user.profile.save()
        return user


class LoginSerializer(serializers.Serializer):
    username = serializers.CharField()
    password = serializers.CharField()
