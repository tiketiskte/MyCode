""" #计算n!//m
def fact(n, m = 1):
    s = 1
    for i in range(1, n + 1):#此处从1 计算到 n + 1 但不包括 n + 1
        s *= i
    return s // m, n, m#返回多个值 元组类型,一种组合数据类型
a, b, c = fact(10)#方式2
print(fact(10))
print(a, b, c)
print(fact(10, 3)) """
""" #计算n!乘数
def fact(n, *b):
    s =1
    for i in range(1, n + 1):
        s *= i
    for iter in b:
        s *= iter
    return s
print(fact(10, 3))#计算10! * 3 """
""" #实验:列表类型全局变量1
ls = ["F", "f"]
def func(a):
    ls.append(a)
    return
func("C")
print(ls) """
""" #实验:列表类型全局变量2
ls = ["F", "f"]
def func(a):
    ls = []#函数内部存内存创建了一个列表类型
    ls.append(a)
    return
func("C")
print(ls) """
#lambda函数
#f = lambda : x + y
#print(f(2, 7))
f = lambda : "憨憨"
print(f())