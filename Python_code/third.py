s = input()
ans = s.split('-')
#print(ans)
print(ans[0] + '+' + ans[5])
""" a = eval(input())
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
print("-----程序结束-----")
 """