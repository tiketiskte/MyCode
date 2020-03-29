A = {"p", "y", 123}
B = set("pypy123")
ans1 = A - B
ans2 = B - A
#print(ans1)
#print(ans2)
""" try:
    while True: #遍历操作
        print(A.pop(), end = "")
except :
    pass """
""" ls = ["p", "p", "y", "y", 123]# 集合元素去重
s = set(ls)
print(s)
ls = list(s) #转变为列表类型,实现了一个去重列表的操作
print(ls) """
""" creature = "cat",  "dog", "tiger", "human"
print(creature)
color = (0x001100, "blue", creature) #元组类型 
print(color) """
""" ls = [ "cat",  "dog", "tiger", 1024]
print(ls)
ls[1: 2] = [1, 2, 3, 4]
print(ls) """
