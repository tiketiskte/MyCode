import requests
import time
""" r = requests.get("https://tiketiskte.cn")
r.status_code
r.encoding = 'utf-8'
r.text
print(r.text) """
""" kv = {'key1': 'value1', 'key2': 'value2'}
r = requests.request('GET', 'http://python123.io/ws',params = kv)
print(r.url) """
# 获取爬取的时间
def getHTMLText(url):
    try:
        r = requests.get(url, timeout = 30)
        r.raise_for_status
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常"
url = "https://www.baidu.com"
starttime = time.time()
for i in range(100):
    getHTMLText(url)
endtime = time.time()
print("爬取100次百度网站所需要的时间为:{:.2f}".format(endtime - starttime))