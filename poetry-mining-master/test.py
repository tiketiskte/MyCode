import matplotlib.pyplot as plt
from wordcloud import WordCloud

# 数据
words = {
    '何处': 1637,
    '不知': 1378,
    '万里': 1293,
    '今日': 1148,
    '春风': 1105,
    '白云': 1065,
    '千里': 1042,
    '不可': 987,
    '不见': 884,
    '人间': 864
}

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 设置中文显示的字体，这里以宋体为例
plt.rcParams['axes.unicode_minus'] = False    # 解决保存图像是负号'-'显示为方块的问题

# 生成词云对象
wordcloud = WordCloud(font_path='C:/Windows/Fonts/simsunb.ttf', width=800, height=400, background_color='white').generate_from_frequencies(words)

# 显示词云图
plt.figure(figsize=(10, 6))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')  # 关闭坐标轴显示
plt.title('古诗词常用词语词云')
plt.show()
