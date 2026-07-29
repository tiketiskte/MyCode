from rest_framework.permissions import BasePermission


class IsOwner(BasePermission):
    """只能操作自己的记录"""

    def has_object_permission(self, request, view, obj):
        return obj.user == request.user
