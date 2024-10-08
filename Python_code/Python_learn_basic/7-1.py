""" tf = open("D:/VS_code/Python_code/Python_learn_basic/7.1.test.txt", "rt")
print(tf.readline())
tf.close()
# 两个文件不可以同时打开 会发生编码错误
bf = open("D:/VS_code/Python_code/Python_learn_basic/7.1.test.txt", "rb")
print(bf.readline())
bf.close() """
fo = open("D:/VS_code/Python_code/Python_learn_basic/7.1.test.txt", "w+") #w+增加读写的功能
ls = ["中国", "法国", "美国"]
fo.writelines(ls)
fo.seek(0) # 移动指针到文件开头(否则不会有输出)
for line in fo:
    print(line)
fo.close()
