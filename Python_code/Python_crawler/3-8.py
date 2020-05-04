import requests
import re
def getHTMLText(url):#获得页面
    try:
        r = requests.get(url, timeout = 30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding #实际判断是否使用
        return r.text
    except:
        return ""

def parsePage(ilt, html):#对页面进行解析 结果返回列表类型
    try:
        plt = re.findall(r'\"view_price\"\:\"[\d\.]*\"', html)
        tlt = re.findall(r'\"raw_title\"\:\".*?\"', html)
        for i in range(len(plt)):
            price = eval(plt[i].split(":")[1])#获得后半部分
            title = eval(tlt[i].split(":")[1])
            ilt.append([price, title])
    except:
        print("")
def printGoodsList(ilt):#信息输出
    tplt = "{:4}\t{:8}\t{:16}" #打印模板
    print(tplt.format("序号", "价格", "商品名称"))
    count = 0
    for g in ilt:
        count = count + 1
        print(tplt.format(count, g[0], g[1]))

def main():
    goods = "书包"
    depth = 2
    start_url = "https://s.taobao.com/search?q=" + goods
    infoList = []
    for i in range(depth):
        try:
            url = start_url + "&s=" + str(44 * i)
            headers = {
                "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.129 Safari/537.36",
                "cookie": "t=faae1d0fb0e6ee4ce362444ce8c21b16; thw=cn; enc=%2F4TIizFaMWjeB0H33o4dRkeo%2FtEqfKBv%2F8Eoi7OUbzRCHZeQU3SNhha%2BZtSSTa5SAuvkvfy5yzT6qkb%2B13bWHQ%3D%3D; hng=CN%7Czh-CN%7CCNY%7C156; cookie2=7494d7bcdcd6e675142cd1a9cd071369; _tb_token_=7bee8503b53ed; alitrackid=www.taobao.com; _samesite_flag_=true; mt=ci=0_0; cna=VRYzFyE7b0cCAXAlnswNfM+L; _m_h5_tk=ed1cdbe11d7059be65d265630b49dd55_1588613422926; _m_h5_tk_enc=324abab8efc3e886d502d54707a8b977; v=0; JSESSIONID=A962839E41BC7BA4593598EC963A7D6B; lastalitrackid=www.taobao.com; l=eBrnlXtmQnar9VCkBO5aourza779mIObzsPzaNbMiIHca6_dtFgMVNQck9FvSdtjgt5AQexyKfwxsRUM87UU-x1Hrt7APlUOrpp6Re1..; isg=BLGxbs6lS_ATD-f4KyD7lFMAwD1LniUQbcT2zJPHqHiQutMM2e-x4f2Y3E7ccr1I; tfstk=cUWPBbTSF8ezLPyA6LpeVPIhmtdRa28H5x-wZ1PkpZ83MWOk7sxEJnqjJn-eW-Al.; sgcookie=EpJ8%2FD%2BhjelciwiYErqMa; unb=3911790050; uc1=pas=0&cookie21=WqG3DMC9FxUx&existShop=false&cookie16=W5iHLLyFPlMGbLDwA%2BdvAGZqLg%3D%3D&cookie15=W5iHLLyFOGW7aA%3D%3D&cookie14=UoTUMtaekyn7mQ%3D%3D; uc3=nk2=EFQniCcC1g%3D%3D&id2=UNk2S5AcpHhcsw%3D%3D&vt3=F8dBxGXNv9%2BfbmI8oRc%3D&lg2=WqG3DMC9VAQiUQ%3D%3D; csg=50102f71; lgc=sjy%5Cu9CB8%5Cu843D; cookie17=UNk2S5AcpHhcsw%3D%3D; dnk=sjy%5Cu9CB8%5Cu843D; skt=8de9ec8e4736ca63; existShop=MTU4ODYwNDEwOQ%3D%3D; uc4=nk4=0%40Eo0JLGrWxCCD9IFl19s2nDrM&id4=0%40Ug48BUqG0CimnwjgU%2FJ1yQUy7VEK; tracknick=sjy%5Cu9CB8%5Cu843D; _cc_=VT5L2FSpdA%3D%3D; _l_g_=Ug%3D%3D; sg=%E8%90%BD0c; _nk_=sjy%5Cu9CB8%5Cu843D; cookie1=UIGnGbEL0SHNGiPdRUB%2Bt2udZMperAOCA%2Bg3eo5cyRA%3D"
            }
            html=requests.get(url,headers=headers)
            print(html.text)
            parsePage(infoList,html.text)
        except:
            continue
    printGoodsList(infoList)

main() 
#参考资料:
""" 
https://www.icourse163.org/learn/BIT-1001870001?tid=1450316449#/learn/forumdetail?pid=1312599462
https://v.qq.com/x/page/f0951sww5ms.html 
"""
