#关于哈姆雷特的解析
""" excludes = {"the", "and", "of", "you", "a", "i", "my", "in"} #设置排除词汇库
def getText(): # 获取文本
    txt = open("Python_code/hamlet.txt", "r").read()
    txt = txt.lower() 
    for ch in '!"#$%&()*+,-./:;<=>?@[\\]^-‘{|}~':
        txt = txt.replace(ch, " ") #归一化结果处理
    return txt
hamleTxt = getText()
words = hamleTxt.split() #列表类型
counts = {}
for word in words:
    counts[word] = counts.get(word, 0) + 1 #逐一遍历列表类型并用字典类型去记录
for word in excludes:
    del(counts[word])
items = list(counts.items()) #先返回所有键值对 然后转换成列表类型
items.sort(key = lambda x:x[1], reverse = True)
for i in range(10):
    word, count = items[i]
    print("{0:<10}{1:>5}".format(word, count)) #左对齐 右对齐宽度 """
#关于三国演义的解析
import jieba
excludes = {"将军", "却说", "荆州", "二人", "不可", "不能", "如何", "商议", "如此"}
txt = open("Python_code/threekingdoms.txt", "r", encoding = 'utf-8').read()
words = jieba.lcut(txt)
counts = {}
for word in words:
    if len(word) == 1:
        continue
    elif word == "诸葛亮" or word == "孔明曰":
        rword = "孔明"
    elif word == "关公" or word == "云长":
        rword = "关羽"
    elif word == "玄德" or word == "玄德曰":
        rword = "刘备"
    elif word == "孟德" or word == "丞相":
        rword = "曹操"
    else:
        rword = word
    counts[rword] = counts.get(rword, 0) + 1 #易出错！！！(缩进要控制好)
for word in excludes:
    del(counts[word])
items = list(counts.items()) 
items.sort(key = lambda x:x[1], reverse = True)
for i in range(10):
    word, count = items[i]
    print("{0:<10} {1:>5}".format(word, count)) 