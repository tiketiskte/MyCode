""" import jieba
import wordcloud
f = open("Python_code/Python_learn_basic/新时代中国特色社会主义.txt", "r", encoding = 'utf-8')
t = f.read()
f.close()
ls = jieba.lcut(t)
txt = " ".join(ls) #列表类型转换成字符串类型
w = wordcloud.WordCloud(font_path = "msyh.ttc", width = 1000, height = 700, background_color = "white")
w.generate(txt)
w.to_file("firstpicture.png") """
import jieba
import wordcloud
from imageio import imread
mask = imread("Python_code/Python_learn_basic/test.jpg") #写你的文件的路径！！！易错!
f = open("Python_code/Python_learn_basic/关于实施乡村振兴战略的意见.txt", "r", encoding = 'utf-8')
t = f.read()
f.close()
ls = jieba.lcut(t)
txt = " ".join(ls) #列表类型转换成字符串类型
w = wordcloud.WordCloud(font_path = "msyh.ttc",mask = mask, width = 1000, height = 700, background_color = "white")
w.generate(txt)
w.to_file("thirdpicture.png")