a = 2
for i in range(3, 100):
    for j in range(2, i):
        if i % j == 0:
            break
        else:
            a += i
print(a)
""" for i in range(1000, 10000):
    s = str(i)
    if pow(eval(s[0]), 4) + pow(eval(s[1]), 4) + pow(eval(s[2]), 4) + pow(eval(s[3]), 4) == i:
        print(i)
import random
import time
import math
DARTS = 1000 * 1000 #表示撒点的数量
hits = 0.0 #表示在圆的内部的数量
start = time.perf_counter()
for i in range(1, DARTS + 1):
    x, y = random.random(), random.random()
    dist = pow(x ** 2 + y ** 2, 0.5)
    if dist <= 1.0:
        hits = hits + 1
pi = 4 * (hits / DARTS)
print("圆周率的值是:{}".format(pi))
print("运行时间:{:.5f}s".format(time.perf_counter() - start))
pi = 0
N = 100
for k in range(N):
    pi += 1/pow(16, k) * ( \
        4 / (8 * k + 1) - 2 / (8 * k + 4) - \
        1 / (8 * k + 5) - 1 / (8 * k + 6) \
    ) 
print("圆周率的值:{}".format(pi))
s = input()
ans = s.split('-')
#print(ans)
print(ans[0] + '+' + ans[5])
a = eval(input())
ans = a**0.5
print("{0:+>30.3f}".format(ans))
import time
scale = 50
print("执行开始".center(scale // 2, '-'))
start = time.perf_counter()
for i in range(scale + 1):
    a, b = '*' * i, '.' * (scale - i)
    c = (i / scale) * 100
    dur = time.perf_counter() - start
    print("\r{:^3.0f}%[{}->{}]{:.2f}s".format(c, a, b, dur), end='')
    time.sleep(0.1)
print("\n" + "程序结束".center(scale // 2, '-'))
for i in range(101):
    print("\r{:2}%".format(i), end = "")
    time.sleep(0.05)
print(time.time())
print("###")
print(time.ctime())
print("###")
print(time.gmtime())

start = time.perf_counter()
end = time.perf_counter()
print(end - start)
scale = 10
print("-----执行开始-----")
for i in range(scale + 1):
    a, b = '**' * i, '..' * (scale - i)
    c = (i / scale) * 100
    print("%{:^3.0f}[{}->{}".format(c, a, b))
print("-----程序结束-----") """