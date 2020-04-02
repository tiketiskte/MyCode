# 自动轨迹绘制
import turtle as t
#建立绘制环境
t.title('自动轨迹绘制')
t.setup(800, 600, 0, 0)
t.pencolor("red")
t.pensize(5)
#数据读入
datals = []
f = open("Python_code/Python_learn_basic/7.2.test.txt")
for line in f:#逐一处理每一行
    line = line.replace("\n", "")# 将换行符转换成空，去掉换行的信息
    #用','分割成字符串 map功能：将第一个函数的功能作用于第二个参数的每一个元素
    datals.append(list(map(eval, line.split(","))))#分割处理
f.close()
#自动绘制
for i in range(len(datals)):
    t.pencolor(datals[i][3], datals[i][4], datals[i][5]) #改变画笔颜色 类似二维数组
    t.fd(datals[i][0])
    if datals[i][1]:
        t.right(datals[i][2])
    else:
        t.left(datals[i][2])
t.hideturtle()
t.done()
#!!!数据驱动的思想方法!!!