#1.
""" str = input()
if str[-1] in ['F', 'f']:
    C = (eval(str[0: -1]) - 32 )/ 1.8
    print("{:.2f}C".format(C))
elif str[-1] in ['C', 'c']:
    F = eval(str[0: -1]) * 1.8 + 32
    print("{:.2f}F".format(F))
else:
    print("输入格式错误") """
#2.
""" print("Hello World") """
#3.
""" temp = "零一二三四五六七八九"
a = input()
for c in a:
    print(temp[eval(c)], end = '') """
#4.
""" str = input()
if str[0] in ['F', 'f']:
    C = (eval(str[1:]) - 32 )/ 1.8
    print("C{:.2f}".format(C))
elif str[0] in ['C', 'c']:
    F = eval(str[1:]) * 1.8 + 32
    print("F{:.2f}".format(F))
else:
    print("输入格式错误") """
#5.
""" str = input()
if str[0] in  ['R']:
    x1 = eval(str[3:]) / 6.78
    print("USD{:.2f}".format(x1))
elif str[0] in ['U']:
    x2 = eval(str[3:]) * 6.78
    print("RMB{:.2f}".format(x2)) """