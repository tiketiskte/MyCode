import turtle
turtle.setup(650, 350, 0, 0)#显示窗体位置 前两个 大小 后两个 坐标
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(25)#设置宽度
turtle.pencolor("purple")#颜色字符串
#turtle.pencolor(0.63, 0.13, 0.94)#RGB的小数值
#turtle.pencolor((0.63, 0.13, 0.94))#RGB的元组值
turtle.seth(-40)#方向控制函数 参数为角度
for i in range(4):#循环 0 ~ 次数-1
    turtle.circle(40, 80)#半径 角度.默认圆心在turtle左侧r距离的位置
    turtle.circle(-40, 80)
turtle.circle(40, 80 / 2)
turtle.fd(40)
turtle.circle(16, 180)
turtle.fd(40 * 2 /3)
turtle.circle(-90, 90)
turtle.done()