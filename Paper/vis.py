import matplotlib.pyplot as plt
import numpy as np

# 1. 设置全局学术风格 (可选)
plt.style.use('seaborn-v0_8-paper') # 或者使用 'bmh'
plt.rcParams['font.family'] = 'serif' # 使用衬线字体更像论文
plt.rcParams['axes.unicode_minus'] = False 

# 模拟数据 (实际应用中请替换为你的模型输出结果)
def get_dummy_data(length=200):
    gt = np.sin(np.linspace(0, 10, length)) + np.random.normal(0, 0.05, length)
    pred = gt + np.random.normal(0, 0.1, length)
    return gt, pred

titles = ['(a) Multiscale mixing', '(b) Scale 0', '(c) Scale 1', '(d) Scale 2', '(e) Scale 3']

# 2. 创建画布：1行5列，设置宽比例
fig, axes = plt.subplots(1, 5, figsize=(20, 4), sharey=True)

for i, ax in enumerate(axes):
    gt, pred = get_dummy_data()
    
    # 绘制折线
    ax.plot(gt, label='GroundTruth', color='#1f77b4', linewidth=1.5, alpha=0.8)
    ax.plot(pred, label='Prediction', color='#ff7f0e', linewidth=1.5, alpha=0.8)
    
    # 3. 细节微调
    ax.set_title(titles[i], fontsize=14, y=-0.25) # 标题放下面
    ax.legend(loc='upper left', fontsize=10, frameon=True)
    ax.grid(True, linestyle='--', alpha=0.5)
    
    # 隐藏顶边和右边框（更简洁）
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

# 调整子图间距
plt.tight_layout()
plt.show()

# 4. 保存为高分辨率 PDF（投稿首选）
# plt.savefig('visualization.pdf', dpi=300, bbox_inches='tight')
