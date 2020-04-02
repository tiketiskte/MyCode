#1.京东页面商品
""" import requests
url = "https://item.jd.com/100005855232.html"
try:
    r = requests.get(url)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[:1000])
except:
    print("爬取失败") """
#2.亚马逊页面商品
""" import requests
r = requests.get("https://www.amazon.cn/gp/product/B01M8L5Z3Y")
print(r.status_code) #显示503 发生了错误
print(r.encoding) #显示ISO-8859-1 要修改编码
r.encoding = r.apparent_encoding
#print(r.text) #出现意外错误
print(r.request.headers)#[User-Agent': python-requests/2.23.0] 不支持
#所以修改我们的头部信息
kv = {'User-Agent': 'Mozilla/5.0'}
url = "https://www.amazon.cn/gp/product/B01M8L5Z3Y"
r = requests.get(url, headers = kv)
print(r.status_code) #返回200 正常
print(r.request.headers)
print(r.text) #返回正常信息 """
#全代码
""" import requests
url = "https://www.amazon.cn/gp/product/B01M8L5Z3Y"
try:
    kv = {'User-Agent': 'Mozilla/5.0'}
    r = requests.get(url, headers = kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[1000: 2000])
except:
    print("爬取失败") """
#3.百度/360搜索关键词提交 并返回结果 注意提交接口的区别 修改键值对的内容即可
""" import requests
keyword = "Python"
try:
    kv = {'wd':keyword}
    r = requests.get("http://www.baidu.com/s", params = kv)
    print(r.request.url)
    r.raise_for_status()
    print(len(r.text))
except:
    print("爬取失败") """
#4.网络图片的爬取和存储 (代码已经检查 无错误)
""" import requests
import os
url = "http://img0.dili360.com/ga/M02/41/AC/wKgBy1cMaiCAX0eFAEv3sh0t2Cs523.tub.jpg"
root = "D:\VS_code\Python_code\Python_crawler\picture"
path = root + url.split('/')[-1] #'/'分割的最后一部分，就是jpg文件的名字
try:
    if not os.path.exists(root):#判断根目录是不是存在，如果不存在，则建立一个根目录
        os.makedirs(root)
    if not os.path.exists(path):#判断文件名是不是存在，如果不存在，则进行爬取
        r = requests.get(url)
        with open(path, 'wb') as f:
            f.write(r.content)#二进制格式写入
            f.close()
            print("文件保存成功")
    else:
        print("文件已存在")
except:
    print("爬取失败") """
#5.IP地址归属地的自动查询[人工来寻找接口]
import requests
url = "https://m.ip138.com/iplookup.asp?ip="
headers={
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.100 Safari/537.36",
}#添加头部进行伪装！！！不然会错！！！
try:
    r = requests.get(url+'202.204.80.112', headers = headers)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[-500:])#输出限制 限制输出的文本 尽量有效简短
except:
    print("爬取失败")
#提交的时候建议挖取该网站的API接口，便于提交,重点是构造URL
