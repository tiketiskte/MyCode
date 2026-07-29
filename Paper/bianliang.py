import matplotlib.pyplot as plt
import numpy as np

# 1. 生成平滑的模拟数据
np.random.seed(88)
t = np.linspace(0, 10, 300)

def smooth_data():
    return np.convolve(np.random.standard_normal(300), np.ones(20)/20, mode='same')

d1 = smooth_data() + np.sin(t*0.5)
d2 = smooth_data() * 0.8  # 待虚化的中间变量
d3 = smooth_data() - np.cos(t*0.3)

# 2. 创建画布，设置 3 行 1 列
fig, axes = plt.subplots(3, 1, figsize=(6, 4), sharex=True)

# 3. 绘制三个变量
# 第一行：蓝色实线
axes[0].plot(t, d1, color='#1f77b4', lw=2)

# 第二行：虚线 + 浅绿色 + 半透明
axes[1].plot(t, d2, color='#4c7273', lw=1.5, ls='--', alpha=0.4)

# 第三行：红色实线
axes[2].plot(t, d3, color='#d62728', lw=2)

# 4. 彻底去掉外框、坐标轴、背景线
for ax in axes:
    ax.axis('off')  # 隐藏所有坐标轴和边框
    # 也可以选择只隐藏框但留白，这里直接彻底去掉

# 调整布局，让波形之间靠得更近
plt.tight_layout()
plt.subplots_adjust(hspace=0.1) # 减小垂直间距

plt.show()