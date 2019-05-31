
# coding: utf-8

# In[1]:

import pandas as pd
import numpy as np


# In[2]:

def gen_train_dic(train):

    for col in ['movieID', 'userID']:
        train[col] = train[col].astype('str')

    train_dic = {}

    for i in range(train.shape[0]):
        userID = train.iloc[i].userID
        movieID = train.iloc[i].movieID
        rate = train.iloc[i].weight_rate
        if userID not in train_dic:
            train_dic[userID] = {}
        train_dic[userID][movieID] = rate
    
    return train_dic    


# In[3]:

# # user_movie倒排表不用建 train_dic本身就是


# In[4]:

def gen_count_ij(train_dic):
    
    count = {}    # 电影ij被同一个用户观看的次数    
    num = {}   # 每部电影被观看的次数

    for user, movies in train_dic.items():
        for i in movies.keys():
            num[i] = num.setdefault(i, 0) + 1
            if i not in count.keys():
                count[i] = {}
            for j in movies.keys():
                if i == j:
                    continue
                else:
                    count[i][j] = count[i].setdefault(j, 0) + 1 / np.log(1 + len(movies))  # 活跃用户降权
    return count, num


# In[5]:

def gen_similarity(count_ij, num):
        
    S = {}   # 相似度矩阵

    for movie, other_movies in count_ij.items():
        if movie not in S:
            S[movie] = {}
        for other_movie, k in other_movies.items():
            S[movie][other_movie] = k / np.sqrt(num[movie] * num[other_movie])
    
    return S


# In[17]:

def itemCFRec(user, K, train_dic, sim):
    
    rank = {}
    seen_movies = train_dic[user]
    
    for movie, rate in seen_movies.items():
        for sim_movie, similarity in sorted(sim[movie].items(), key=lambda x:x[1], reverse=True)[0:K]:  # 取topK相似电影
            if sim_movie in seen_movies.keys():
                pass
            else:
                rank[sim_movie] = rank.setdefault(sim_movie, 0) + rate * similarity
            
    return rank


# In[6]:

train = pd.read_csv('tmp.csv')
train.drop(['rating', 'time_weight'], axis=1, inplace=True)

for col in ['movieID', 'userID']:
    train[col] = train[col].astype('str')


# In[7]:

train_dic = gen_train_dic(train)


# In[8]:

count_ij, num = gen_count_ij(train_dic)


# In[9]:

sim = gen_similarity(count_ij, num)


# In[18]:

rank = itemCFRec(user='1', K=3, train_dic=train_dic, sim=sim)


# In[ ]:
rec = sorted(rank.items(), key=lambda x:x[1], reverse=True)[:20]

print(rec)

