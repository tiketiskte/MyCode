import math
def getNum():# 循环获得用户输入的内容
    nums = []
    iNumStr = input("请输入数字(回车退出):")
    while iNumStr != '':
        nums.append(eval(iNumStr))
        iNumStr = input("请输入数字(回车退出):")
    return nums
def mean(numbers):# 计算平均值
    s = 0.0
    for num in numbers:
        s += num
    return s / len(numbers)
def dev(numbers, mean):# 计算方差
    sdev = 0.0
    for num in numbers:
        sdev += (num - mean) ** 2
    return math.sqrt(sdev / (len(numbers) - 1))
def median(numbers):
    sorted(numbers)
    size = len(numbers)
    if size % 2 == 0:
        med = (numbers[size // 2 - 1] + numbers[size // 2]) / 2
    else:
        med = numbers[size // 2]
    return med
n = getNum()
m = mean(n)
print("平均值:{},方差:{:.2f},中位数:{}".format(m, dev(n, m), median(n)))
