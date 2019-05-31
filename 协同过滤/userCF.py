
import pandas as pd
import numpy as np



train = pd.read_csv('tmp.csv')

train.drop(['rating', 'time_weight'], axis=1, inplace=True)



for col in ['movieID', 'userID']:
    train[col] = train[col].astype('str')




my_dic = {}

for i in range(train.shape[0]):
    userID = train.iloc[i].userID
    movieID = train.iloc[i].movieID
    rate = train.iloc[i].weight_rate
    if userID not in my_dic:
        my_dic[userID] = {}
    my_dic[userID][movieID] = rate   
    


movie_user = {}


# movie_user倒排表
for user, movies in my_dic.items():
    for movie in movies.keys():
        if movie not in movie_user:
            movie_user[movie] = set()
        movie_user[movie].add(user)
  


# 用户uv共同看过的电影部数
count = {}
# 用户自己看过的电影部数
num = {}




for movie, users in movie_user.items():
    for u in users:
        num[u] = num.setdefault(u, 0) + 1
        if u not in count:
            count[u] = {}
        for v in users:
            if u == v:
                continue
            else:
                if v not in count[u].keys():
                    count[u][v] = 0
                count[u][v] += 1 / np.log(1 + len(users))



#计算相似度Similarity
S = {}


for user, other_users in count.items():
    if user not in S:
        S[user] = {}
    for other_user, k in other_users.items():
        S[user][other_user] = k/np.sqrt(num[user]*num[other_user])


def userCFRec(user, my_dic, K):
    rank = {}
    seen_movies = my_dic[user]
    for v, sim in sorted(S[user].items(),key=lambda x:x[1], reverse=True)[0:K]:
        for movie, score in my_dic[v].items():
            if movie in seen_movies.keys():
                pass
            else:
                rank[movie] = rank.setdefault(movie, 0) + score * sim
    return rank    



RES = userCFRec(user='1', my_dic=my_dic, K = 3)



sorted(RES.items(), key=lambda x:x[1], reverse=True)




