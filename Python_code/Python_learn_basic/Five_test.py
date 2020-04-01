#5-1
""" import random

def genpwd(length):
    a = pow(10, length - 1)
    b = pow(10, length) - 1
    return random.randint(a, b)
length = eval(input())
random.seed(17)
for i in range(3):
    print(genpwd(length)) """ 
#5-2
""" def prime(m):
    for i in range(2, m):
        if m % i == 0:
            return False
    return True
n = eval(input())
n = int(n)
count = 5
while count > 0:
    if(prime(n)):
        if count > 1:
            print(n, end=',')
        else:
            print(n, end='')
        count -= 1
    n += 1  """