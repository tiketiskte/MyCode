#6-1.
""" N = input()
s = set(N)
ans = 0
for i in s:
    ans += eval(i)
print(ans) """
#6-2.
""" s = '''双儿 洪七公 赵敏 赵敏 逍遥子 鳌拜 殷天正 金轮法王 乔峰 杨过 洪七公 郭靖 
       杨逍 鳌拜 殷天正 段誉 杨逍 慕容复 阿紫 慕容复 郭芙 乔峰 令狐冲 郭芙 
       金轮法王 小龙女 杨过 慕容复 梅超风 李莫愁 洪七公 张无忌 梅超风 杨逍 
       鳌拜 岳不群 黄药师 黄蓉 段誉 金轮法王 忽必烈 忽必烈 张三丰 乔峰 乔峰 
       阿紫 乔峰 金轮法王 袁冠南 张无忌 郭襄 黄蓉 李莫愁 赵敏 赵敏 郭芙 张三丰 
       乔峰 赵敏 梅超风 双儿 鳌拜 陈家洛 袁冠南 郭芙 郭芙 杨逍 赵敏 金轮法王 
       忽必烈 慕容复 张三丰 赵敏 杨逍 令狐冲 黄药师 袁冠南 杨逍 完颜洪烈 殷天正 
       李莫愁 阿紫 逍遥子 乔峰 逍遥子 完颜洪烈 郭芙 杨逍 张无忌 杨过 慕容复 
       逍遥子 虚竹 双儿 乔峰 郭芙 黄蓉 李莫愁 陈家洛 杨过 忽必烈 鳌拜 王语嫣 
       洪七公 韦小宝 阿朱 梅超风 段誉 岳灵珊 完颜洪烈 乔峰 段誉 杨过 杨过 慕容复 
       黄蓉 杨过 阿紫 杨逍 张三丰 张三丰 赵敏 张三丰 杨逍 黄蓉 金轮法王 郭襄 
       张三丰 令狐冲 赵敏 郭芙 韦小宝 黄药师 阿紫 韦小宝 金轮法王 杨逍 令狐冲 阿紫 
       洪七公 袁冠南 双儿 郭靖 鳌拜 谢逊 阿紫 郭襄 梅超风 张无忌 段誉 忽必烈 
       完颜洪烈 双儿 逍遥子 谢逊 完颜洪烈 殷天正 金轮法王 张三丰 双儿 郭襄 阿朱 
       郭襄 双儿 李莫愁 郭襄 忽必烈 金轮法王 张无忌 鳌拜 忽必烈 郭襄 令狐冲 
       谢逊 梅超风 殷天正 段誉 袁冠南 张三丰 王语嫣 阿紫 谢逊 杨过 郭靖 黄蓉 
       双儿 灭绝师太 段誉 张无忌 陈家洛 黄蓉 鳌拜 黄药师 逍遥子 忽必烈 赵敏 
       逍遥子 完颜洪烈 金轮法王 双儿 鳌拜 洪七公 郭芙 郭襄 赵敏'''
ls = s.split()
d = {}
for i in ls:
    d[i] = d.get(i, 0) + 1
maxname, max_cnt = "", 0
for k in d:
    if d[k] > max_cnt:
        maxname, max_cnt = k, d[k]
print(maxname) """
#6 - 1:
""" import math
def getNum():# 循环获得用户输入的内容
    s = input()
    nums = list(eval(s))
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
    numbers.sort()
    size = len(numbers)
    if size % 2 == 0:
        med = (numbers[size // 2 - 1] + numbers[size // 2]) / 2
    else:
        med = numbers[size // 2]
    return med
n = getNum()
m = mean(n)
print("平均值:{:.2f},标准差:{:.2f},中位数:{}".format(m, dev(n, m), median(n)))
 """
#6 - 2:
def getText(): # 获取文本
    txt = open("Python_code\Python_learn_basic\hamlet.txt", "r").read()
    txt = txt.lower() 
    for ch in '!"#$%&()*+,-./:;<=>?@[\\]^-‘{|}~':
        txt = txt.replace(ch, " ") #归一化结果处理
    return txt
hamleTxt = getText()
words = hamleTxt.split() #列表类型
counts = {}
for word in words:
    counts[word] = counts.get(word, 0) + 1 #逐一遍历列表类型并用字典类型去记录
items = list(counts.items()) #先返回所有键值对 然后转换成列表类型
items.sort(key = lambda x:x[1], reverse = True)
for i in range(10):
    word = items[i]
    print(word) #左对齐 右对齐宽度
