import requests
from bs4 import BeautifulSoup
import bs4

def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        #printUnivList(r.url)
        return (r.text)
    except:
        return ""

def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find("tbody").contents:
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string, tds[1].string, tds[2].string])

def printUnivList(ulist, num): #num表示打印多少个
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"#表示输出模板
    print(tplt.format("排名", "学校名称", "总分", chr(12288)))#中文填充表示 参考链接:https://www.cnblogs.com/zhz-8919/p/9767357.html
    for i in range(num):
        u = ulist[i]
        print(tplt.format(u[0], u[1], u[2], chr(12288)))

def main():
    unifo=[]
    url="http://www.zuihaodaxue.com/zuihaodaxuepaiming2019.html"    
    html=getHTMLText(url)
    fillUnivList(unifo,html)
    printUnivList(unifo,20)
    
main()
#和源代码不同，这里children会报错 我们把children改成contents 搜索即可
#中文输出排版注意