from django.contrib.auth import authenticate
from rest_framework import status
from rest_framework.decorators import api_view, permission_classes
from rest_framework.permissions import AllowAny, IsAuthenticated
from rest_framework.response import Response
from rest_framework_simplejwt.tokens import RefreshToken

from .serializers import RegisterSerializer, UserSerializer


@api_view(["POST"])
@permission_classes([AllowAny])
def register(request):
    serializer = RegisterSerializer(data=request.data)
    serializer.is_valid(raise_exception=True)
    user = serializer.save()
    refresh = RefreshToken.for_user(user)
    return Response(
        {
            "user": UserSerializer(user).data,
            "access": str(refresh.access_token),
            "refresh": str(refresh),
        },
        status=status.HTTP_201_CREATED,
    )


@api_view(["POST"])
@permission_classes([AllowAny])
def login(request):
    username = request.data.get("username")
    password = request.data.get("password")
    if not username or not password:
        return Response(
            {"error": "请输入用户名和密码"}, status=status.HTTP_400_BAD_REQUEST
        )
    user = authenticate(username=username, password=password)
    if user is None:
        return Response(
            {"error": "用户名或密码错误"}, status=status.HTTP_401_UNAUTHORIZED
        )
    refresh = RefreshToken.for_user(user)
    return Response(
        {
            "user": UserSerializer(user).data,
            "access": str(refresh.access_token),
            "refresh": str(refresh),
        }
    )


@api_view(["GET", "PATCH"])
def me(request):
    if request.method == "GET":
        return Response(UserSerializer(request.user).data)

    # PATCH: 更新资料（支持表单和 JSON）
    display_name = request.data.get("display_name")
    username = request.data.get("username")
    avatar = request.FILES.get("avatar")

    if display_name is not None:
        request.user.profile.display_name = display_name
        request.user.profile.save()
    if username is not None:
        request.user.username = username
        request.user.save()
    if avatar:
        # 删除旧头像
        if request.user.profile.avatar:
            request.user.profile.avatar.delete(save=False)
        request.user.profile.avatar = avatar
        request.user.profile.save()

    return Response(UserSerializer(request.user).data)


@api_view(["POST"])
@permission_classes([IsAuthenticated])
def refresh_token(request):
    refresh = request.data.get("refresh")
    if not refresh:
        return Response({"error": "缺少 refresh token"}, status=400)
    try:
        token = RefreshToken(refresh)
        return Response({"access": str(token.access_token)})
    except Exception:
        return Response({"error": "无效的 refresh token"}, status=401)
