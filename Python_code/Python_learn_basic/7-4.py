# 从CSV格式文件中读入数据
fo = open(fname)
ls = []
for line in fo:
    line = line.replace("\n", "")# 将换行符进行替换为空格形式 仅仅去掉换行符
    ls.append(line.split(","))
fo.close()

#将数据写入CSV格式的文件
ls = [[], [], []]# 二维列表 存储要写入的数据
f = open(fname, 'w')
for item in ls:
    f.write(','.join(item) + '\n')
f.close()

#遍历CSV格式文件
ls =  [[1,2], [3, 4], [5, 6]]
for row in ls:
    for column in row:
        print(column)