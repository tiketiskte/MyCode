import matplotlib.pyplot as plt
import numpy as np

# 1. 设置参数
np.random.seed(88)
t = np.linspace(0, 10, 300)

def generate_regular_data(phase, freq, noise_scale=0.1):
    # 基础规律信号：正弦波 + 线性趋势
    base = np.sin(t * freq + phase) + 0.1 * t
    # 叠加少量平滑噪声，保持真实感但不凌乱
    noise = np.convolve(np.random.standard_normal(300), np.ones(10)/10, mode='same')
    return base + noise * noise_scale

# 生成三组有规律的数据
# 设定不同的频率和相位，使它们看起来有区分度
d1 = generate_regular_data(phase=0, freq=0.8)   # 顶部蓝线
d2 = generate_regular_data(phase=1.5, freq=1.2) # 中间虚化线
d3 = generate_regular_data(phase=3.0, freq=0.6) # 底部红线

# 2. 创建画布
fig, axes = plt.subplots(3, 1, figsize=(6, 4), sharex=True)

# 3. 绘制
# 第一行：蓝色实线 - 规律性强
axes[0].plot(t, d1, color='#1f77b4', lw=2.5)

# 第二行：浅绿色 + 虚线 + 半透明 - 模拟中间变量/预测不确定性
axes[1].plot(t, d2, color='#4c7273', lw=1.5, ls='--', alpha=0.4)

# 第三行：红色实线 - 目标/输出
axes[2].plot(t, d3, color='#d62728', lw=2.5)

# 4. 彻底去掉外框、坐标轴
for ax in axes:
    ax.axis('off')

# 调整布局
plt.tight_layout()
plt.subplots_adjust(hspace=-0.1) # 进一步拉近距离，形成整体感

plt.show()