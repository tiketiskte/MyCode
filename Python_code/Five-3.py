""" import turtle
def koch(size, n):
    if n == 0:
        turtle.fd(size)
    else:
        for angle in [0, 60, -120, 60]:
            turtle.left(angle)
            koch(size / 3, n - 1)
def main():
    turtle.setup(800, 400)# 设置屏幕位置
    turtle.penup()# 抬起画笔 移动到合适位置
    turtle.goto(-300, -50)# 移动
    turtle.pendown()# 放下画笔 准备作图
    turtle.pensize(2)
    koch(600, 3)
    turtle.hideturtle()# 隐藏画笔的形状
    turtle.done()
main() """
import turtle
def koch(size, n):
    if n == 0:
        turtle.fd(size)
    else:
        for angle in [0, 60, -120, 60]:
            turtle.left(angle)
            koch(size / 3, n - 1)
def main():
    turtle.setup(600, 600)
    turtle.speed(0)# 控制画笔的速度
    turtle.penup()
    turtle.goto(-200, 100)
    turtle.pendown()
    turtle.pensize(2)
    turtle.write('王', font=('Arial', 18, 'normal'))
    turtle.fd(40)
    turtle.write('瑶', font=('Arial', 18, 'normal'))
    turtle.fd(40)
    turtle.write('是', font=('Arial', 18, 'normal'))
    turtle.fd(40)
    turtle.write('猪', font=('Arial', 18, 'normal'))
    turtle.fd(40)
    turtle.hideturtle()
    turtle.done()
    """ level = 5
    koch(400, level)
    turtle.right(120)
    koch(400, level)
    turtle.right(120)
    koch(400, level)
    turtle.hideturtle()
    turtle.done() """
main()