import matplotlib.pyplot as plt

# --- 核心数据提取自 Table 3 ---
levels = [2, 3, 4]

# 数据结构: {名称: {'mse': [L2, L3, L4], 'mae': [L2, L3, L4]}}
data = {
    'ETTh1_336': {'mse': [0.432, 0.426, 0.430], 'mae': [0.458, 0.452, 0.456]},
    'ETTh1_720': {'mse': [0.455, 0.449, 0.453], 'mae': [0.471, 0.466, 0.469]},
    'ETTh2_336': {'mse': [0.395, 0.390, 0.394], 'mae': [0.449, 0.444, 0.448]},
    'ETTh2_720': {'mse': [0.408, 0.403, 0.407], 'mae': [0.458, 0.453, 0.457]},
    'ETTm1_336': {'mse': [0.375, 0.370, 0.374], 'mae': [0.341, 0.335, 0.339]},
    'ETTm1_720': {'mse': [0.383, 0.376, 0.380], 'mae': [0.350, 0.345, 0.348]},
}

# 颜色方案：ETTh1(蓝), ETTh2(红), ETTm1(绿)
colors = {'ETTh1': '#1f77b4', 'ETTh2': '#d62728', 'ETTm1': '#2ca02c'}

# 1. 调整整体比例 (14:7 使右侧留白更自然)
fig, ax = plt.subplots(figsize=(14, 7))

# 遍历数据绘图
for name, metrics in data.items():
    dataset, horizon = name.split('_')
    color = colors[dataset]
    
    # 区分不同预测长度的透明度和标记
    # 720 使用实心圆，336 使用空心圆
    alpha_val = 1.0 if horizon == '720' else 0.5
    m_style = 'o' if horizon == '720' else 's'
    
    # 绘制 MSE (实线)
    ax.plot(levels, metrics['mse'], color=color, linestyle='-', marker=m_style, 
            linewidth=2.5, alpha=alpha_val, label=f"{name} (MSE)")
    
    # 绘制 MAE (虚线)
    ax.plot(levels, metrics['mae'], color=color, linestyle='--', marker=m_style, 
            linewidth=1.8, alpha=alpha_val, label=f"{name} (MAE)")

# --- 细节打磨 ---
ax.set_xlabel('Decomposition Level (m)', fontsize=13, labelpad=10)
ax.set_ylabel('(MSE/MAE)', fontsize=13, labelpad=10)
# ax.set_title('WPMixer: Performance with varying level of decomposition m', fontsize=15, pad=20)

# 坐标轴刻度设置
ax.set_xticks(levels)
ax.grid(True, linestyle='--', alpha=0.4)
ax.tick_params(axis='both', which='major', labelsize=11)

# 2. 图例放置在右侧下部 (Outside lower right)
# bbox_to_anchor 的第一个参数控制左右，第二个控制上下
ax.legend(bbox_to_anchor=(1.02, 0), loc='lower left', 
          borderaxespad=0, fontsize=10, frameon=True, ncol=1)

# 调整布局，为右侧图例留出空间
plt.subplots_adjust(right=0.82) 

# 展示
plt.show()