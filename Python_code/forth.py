""" height, weight = eval(input("请输入身高(米)和体重(公斤)[逗号隔开]:"))
bmi = weight / pow(height, 2)
print("BMI的数值为:{:.2f}".format(bmi))
who, dom = "", ""
if bmi < 18.5:
    who = "偏瘦"
elif  bmi < 25:
    who = "正常"
elif bmi < 30:
    who = "偏胖"
else:
    who = "肥胖"

if bmi < 18.5:
    dom = "偏瘦"
elif  bmi < 24:
    dom = "正常"
elif bmi < 28:
    dom = "偏胖"
else:
    dom = "肥胖"
print("BMI指标为:国际'{0}', 国内'{1}'".format(who, dom))
guess = eval(input())
if guess >= 60 and guess < 70:
    print("D")
elif guess >= 70 and guess < 80:
     print("C")
elif guess >= 80 and guess < 90:
    print("B")
else: 
    print("A")
print("猜{}了".format("对" if guess == 99 else "错"))
print(guess)
if guess == 99:
    print("hhh~")
 """