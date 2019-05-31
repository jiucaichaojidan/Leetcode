
import numpy as np



num_try = 500   # number of try
num_arms = 10  # number of arms



def thompson(num_arms,num_try):
    
    my_choice = []   # 存放每次选择的arm
    win = np.ones(num_arms)   # num of wins
    lose = np.ones(num_arms)  # num of lose
    p = np.random.rand(num_arms)  # 随机生成的概率，可理解为user对特定category喜欢的概率/程度
    
    for i in range(num_try):
        
        choice = np.argmax(np.random.beta(win, lose))
        res = np.random.binomial(1, p[choice] )  # 二项分布（点击/不点击)
        win[choice] = win[choice] + res
        lose[choice] = lose[choice] + (1 - res) 
        
        my_choice.append(choice)
        
    return my_choice, p



def ucb(num_arms, num_try):
    
    my_choice = []
    profit = np.zeros(num_arms)  # 当前步数下每个arm的收益
    count = np.zeros(num_arms)   # 每个arm被选中的次数
    p = np.random.rand(num_arms)
    
    for i in range(num_try):
        score = profit + np.sqrt( 2 * np.log(i + 1) / (count + 0.0001))
        choice = np.argmax(score)
        res = np.random.binomial(1, p[choice])
        profit[choice] = (profit[choice] * count[choice] + res)/(count[choice] + 1)
        count[choice] += 1
        
        my_choice.append(choice)
    
    return my_choice, p
        



def epsilon_greedy(num_arms, num_try,epsilon = 0.2, decay_rate=0.999, min_e=0.1):
   
    my_choice = []
    profit = np.zeros(num_arms)
    count = np.zeros(num_arms)
    p = np.random.rand(num_arms)
    choice = 0
    
    for i in range(num_try):
        epsilon = min(epsilon * decay_rate, min_e)   # epsilon衰减
        
        if np.random.rand() > epsilon:  
            choice = np.argmax(profit)    # exploit
        else:    
            choice = np.random.randint(num_arms)   # explore
        
        res = np.random.binomial(1, p[choice])
        profit[choice] = (profit[choice] * count[choice] + res)/(count[choice] + 1)   # 重新计算收益
        count[choice] += 1
        
        my_choice.append(choice)
        
    return my_choice, p        




th_choice, th_p = thompson(num_arms=num_arms, num_try=num_try)


u_choice, u_p = ucb(num_arms=num_arms, num_try=1000)


e_choice, e_p = epsilon_greedy(num_arms=num_arms, num_try=num_try)




