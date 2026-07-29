import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Rectangle

# 1. 设置颜色数据 (4x4 矩阵)
# 我们用数值来代表颜色深度
data = np.random.rand(4, 4)

# 定义颜色映射 (使用类似图中的红-黄-蓝调色板)
cmap = plt.cm.RdYlBu_r 

fig, ax = plt.subplots(figsize=(4, 4))

# 2. 循环绘制每一个小色块
for i in range(4):
    for j in range(4):
        if i == 2:
            # 中间第三行：设置为淡绿色，无边框
            color = '#e8f5e9' 
            rect = Rectangle((j, 3-i), 1, 1, facecolor=color, edgecolor='none')
            ax.add_patch(rect)
            # 在中间块画一个小横杠 "-"
            if j == 1 or j == 2: # 模仿图中横跨中间的效果
                 ax.text(j + 0.5, 3-i + 0.5, '-', ha='center', va='center', 
                         color='#7f8c8d', fontsize=15, fontweight='bold')
        else:
            # 其他行：根据随机数据填充颜色
            color = cmap(data[i, j])
            rect = Rectangle((j, 3-i), 1, 1, facecolor=color, edgecolor='none')
            ax.add_patch(rect)

# 3. 隐藏坐标轴和边框
ax.set_xlim(0, 4)
ax.set_ylim(0, 4)
ax.axis('off')

# 4. 调整布局，使其紧凑
plt.gca().set_aspect('equal', adjustable='box')
plt.tight_layout()

plt.show()