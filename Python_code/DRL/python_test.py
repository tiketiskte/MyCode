import numpy as np
import matplotlib.pyplot as plt

# 假设有一些状态和动作的集合
states = range(5)  # 状态空间
actions = range(2)  # 动作空间，假设0表示左，1表示右

# 初始化值函数
v = np.zeros(len(states))

# 折扣因子
gamma = 0.9

# 收敛阈值
threshold = 1e-6

# 转移概率函数 p(s'|s, a)
def transition_prob(s, a, s_prime):
    return 1.0 / len(states)

# 奖励函数 r(s, a)
def reward(s, a):
    return s + a

# 值迭代算法
def value_iteration(states, actions, v, gamma, threshold):
    iteration = 0
    policy_iterations = []
    flag = 0
    while True:
        delta = 0
        new_v = v.copy()
        flag = flag + 1
        for s in states:
            q_values = []
            for a in actions:
                q_value = sum(transition_prob(s, a, s_prime) * (reward(s, a) + gamma * v[s_prime]) for s_prime in states)
                q_values.append(q_value)
            
            max_q_value = max(q_values)
            new_v[s] = max_q_value
            delta = max(delta, abs(new_v[s] - v[s]))
        
        v = new_v
        iteration += 1
        
        # Policy extraction
        policy = np.zeros(len(states))
        for s in states:
            q_values = []
            for a in actions:
                q_value = sum(transition_prob(s, a, s_prime) * (reward(s, a) + gamma * v[s_prime]) for s_prime in states)
                q_values.append(q_value)
            
            best_action = np.argmax(q_values)
            policy[s] = best_action
        
        policy_iterations.append(policy.copy())
        
        if delta < threshold:
            break
    print(flag)
    return v, policy, policy_iterations

# 运行值迭代算法
optimal_value_function, optimal_policy, policy_iterations = value_iteration(states, actions, v, gamma, threshold)

# 可视化策略的迭代过程
def plot_policy_iterations(policy_iterations):
    fig, axs = plt.subplots(len(policy_iterations), 1, figsize=(10, len(policy_iterations) * 2))
    
    for i, policy in enumerate(policy_iterations):
        ax = axs[i]
        ax.set_xlim(-1, len(states))
        ax.set_ylim(-1, 1)
        ax.set_title(f'Iteration {i+1}')
        ax.set_yticks([])
        ax.set_xticks(np.arange(len(states)))
        ax.set_xticklabels([f'S{state}' for state in states])
        
        for state in states:
            action = policy[state]
            if action == 0:  # 假设动作0表示向左
                ax.arrow(state, 0, -0.2, 0, head_width=0.2, head_length=0.1, fc='k', ec='k')
            elif action == 1:  # 假设动作1表示向右
                ax.arrow(state, 0, 0.2, 0, head_width=0.2, head_length=0.1, fc='k', ec='k')
    
    plt.tight_layout()
    plt.show()

print("Optimal Value Function:")
print(optimal_value_function)
print("Optimal Policy:")
print(optimal_policy)


plot_policy_iterations(policy_iterations)
