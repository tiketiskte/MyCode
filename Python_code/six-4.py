d = {}
d["憨憨"] = "王瑶"
d["臭猪"] = "臭猪瑶"
print(d)
d["臭猪"] = "肥瑶"
print(d)
print("臭猪" in d)
print(len(d))
d.clear()
print(d)
#jieba库
import jieba
print(jieba.lcut('欢迎新老师生前来就餐')) # 列表类型
ans1 = jieba.cut('欢迎新老师生前来就餐') # 迭代类型
ans = 'Full mode :' + ' '.join(ans1)
print(ans)