import requests
from bs4 import BeautifulSoup
import traceback
import re

def  getHtmlText(url, code = 'utf-8'):#获取url链接
    try:
        r = requests.get(url)
        r.raise_for_status()
        #r.encoding = r.apparent_encoding #优化 人工分析
        r.encoding = code
        return r.text
    except:
        return ""

def getStockList(lst, stockURL):#获取所有股票的信息组成列表
    html = getHtmlText(stockURL, "GB2312")
    soup = BeautifulSoup(html, 'html.parser')
    a = soup.find_all('a')#寻找这个标签
    for i in a:
        try:
            href = i.attrs['href']
            lst.append(re.findall(r"[s][hz]\d{6}", href)[0])
        except:
            continue

def getStockInfo(lst, stockURL, fpath):#获取个股的信息
    count = 0#计数变量
    for stock in lst:
        url = stockURL + stock + ".html"
        html = getHtmlText(url)
        try:
            if html == "":
                continue
            infoDict = {}
            soup = BeautifulSoup(html, 'html.parser')
            stockInfo = soup.find('div', attrs = {'class':'stock-bets'})

            name = stockInfo.findall(attrs = {'class':'bets-name'})[0]
            infoDict.update({'股票名称' : name.text.split()[0]})
            keyList = stockInfo.find_all('dt')#获得键值对
            valueList = stockInfo.find_all('dd')
            for i in range(len(keyList)):
                key = keyList[i].text
                val = valueList[i].text
                infoDict[key] = val
            with open(fpath, 'a', encoding = 'utf-8') as f:
                f.write(str(infoDict) + '\n')
                count = count + 1
                print("\r当前进度:{:.2f}%".format(count * 100 / len(lst)), end = "")
        except:
            count = count + 1
            print("\r当前进度:{:.2f}%".format(count * 100 / len(lst)), end = "")
            #traceback.print_exc()#获得错误信息异常等
            continue

def main():
    stock_list_url = 'https://quote.eastmoney.com/stocklist.html'
    stock_info_url = 'https://gupiao.baidu.com/stock/'
    output_file = 'D://BaiduStockInfo.txt'
    slist = []
    getStockList(slist, stock_list_url)
    getStockInfo(slist, stock_info_url, output_file)

main()