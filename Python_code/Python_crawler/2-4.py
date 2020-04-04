import requests
from bs4 import BeautifulSoup 
r = requests.get("http://python123.io/ws/demo.html")
#print(r.text)
demo = r.text
soup = BeautifulSoup(demo, 'html.parser')
#print(soup.prettify())
""" print(soup.head)
print(soup.head.contents) """ #一个列表类型
for parent in soup.a.parents:
    if parent is None:
        print(parent)
    else:
        print(parent.name)