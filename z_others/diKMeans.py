import numpy as np
import pandas as pd
import random

"""
二分kMeans
调用kMeans(k=2)把一个簇类分成两个，迭代此过程，直至成k个
1.初始化簇类表，使之包含所有数据
2.kMeans, k=2
3.计算划分后的误差，选择所有被划分的cluster中总误差最小的划分方式。误差可用平方误差SSE衡量，平方和损失，衡量的是方差
4.迭代2/3步骤，直至cluster数目达到k后停止

优点:
1.加速，减少相似度计算次数
2.能够克服kMeans收敛局部最优的问题
"""

import numpy as np
import pandas as pd
import random


class kMeans:
    def __init__(self):
        pass
    
    def loadData(self, file):
        return pd.read_csv(file, header=0, sep=',')

    def filterAnomalyValue(self, data):
        '''
        去除异常值
        '''
        upper = np.mean(data['price']) + 3 * np.std(data['price'])
        lower = np.mean(data['price']) - 3 * np.std(data['price'])
        upper_limit = upper if upper > 5000 else 5000
        lower_limit = lower if lower < 1 else 1
        print("最大异常值为 {}, 最小异常值为 {}".format(upper_limit, lower_limit))
        newData = data[(data['price'] < upper_limit) & (data['price'] > lower_limit)]
        return newData, upper_limit, lower_limit
    
    def initCenters(self, values, K, cluster):
        '''
        初始化聚类中心
        '''
        random.seed()
        oldCenters = list()
        # 遍历第i个聚类中心，共K个
        for i in range(K):
            index = random.randint(0, len(values))
            cluster.setdefault(i, {}) # {i: {'center': c, 'values': []}}
            cluster[i]['center'] = values[index] # 随机选择一个数据点作为聚类中心
            cluster[i]['values'] = [] # 后续存放属于该聚类中心的点
            oldCenters.append(values[index])
        return oldCenters, cluster
    
    def SSE(self, data, mean):
        newData = np.mat(data) - mean
        return (newData * newData.T).tolist()[0][0]

    def diKMeans(self, data, k=3):
        clusterSSEResult = dict()
        clusterSSEResult.setdefault(0, {})
        clusterSSEResult[0]['values'] = data
        clusterSSEResult[0]['sse'] = 1e9
        clusterSSEResult[0]['center'] = np.mean(data)

        while len(clusterSSEResult) < k:
            # 找到最大SSE值对应的数据，进行kMeans聚类
            maxSSE = -1e9
            maxSSEKey = 0
            for key in clusterSSEResult.keys():
                if clusterSSEResult[key]['sse'] > maxSSE:
                    maxSSE = clusterSSEResult[key]['sse']
                    maxSSEKey = key
            clusterResult = self.kMeans(clusterSSEResult[maxSSEKey]['values'], K=2, maxIters=10)

            # 删除clusterSSE中的mainkey字段
            del clusterSSEResult[maxSSEKey]

            # 将新聚类的结果赋值给clusterSSEResult
            clusterSSEResult.setdefault(maxSSEKey, {})
            clusterSSEResult[maxSSEKey]['center'] = clusterResult[0]['center']
            clusterSSEResult[maxSSEKey]['values'] = clusterResult[0]['values']
            clusterSSEResult[maxSSEKey]['sse'] = self.SSE(clusterResult[0]['values'], clusterResult[0]['center'])

            maxKey = max(clusterSSEResult.keys()) + 1
            clusterSSEResult.setdefault(maxKey, {})
            clusterSSEResult[maxKey]['center'] = clusterResult[1]['center']
            clusterSSEResult[maxKey]['values'] = clusterResult[1]['values']
            clusterSSEResult[maxKey]['sse'] = self.SSE(clusterResult[1]['values'], clusterResult[1]['center'])

            return clusterSSEResult

    def distance(self, price1, price2):
        return np.emath.sqrt(pow(price1-price2, 2))
        
    def kMeans(self, data, K, maxIters):
        cluster = dict()  # 最终的聚类结果
        oldCenters, cluster = self.initCenters(data, K, cluster)
        print('初始化的聚类中心为: {}'.format(oldCenters))

        # 迭代停止条件: 聚类中心不再变化，或者达到最大迭代次数
        clusterChanged = True
        i = 0
        while clusterChanged:
            # 遍历每条数据，把数据归类到最近的聚类中心
            for price in data:
                minDistance = 1e9
                minIndex = -1
                # 遍历每个聚类中心
                for key in cluster.keys():
                    dis = self.distance(price, cluster[key]['center'])
                    if dis < minDistance:
                        minDistance = dis
                        minIndex = key
                cluster[minIndex]['values'].append(price)
                
            # 更新聚类中心
            newCenters = []
            for key in cluster.keys():
                newCenter = np.mean(cluster[key]['values'])
                cluster[key]['center'] = newCenter
                newCenters.append(newCenter)
            print('第 {} 次迭代后聚类中心为 {}'.format(i, newCenter))

            # 迭代退出条件
            if oldCenters == newCenters or i > maxIters:
                clusterChanged = False
            else:
                oldCenters = newCenters
                i += 1
                # 删除cluster中的记录
                for key in cluster.keys():
                    cluster[key]['values'] = []
            
        return cluster
        

if __name__ == '__main__':
    file = './data/sku_price.csv'
    km = kMeans()
    data = km.loadData(file)
    newData, upper_limit, lower_limit = km.filterAnomalyValue(data)
    clusterSSE = km.diKMeans(newData['price'].values, k=5)
    print(clusterSSE)


"""
最大异常值为 5000, 最小异常值为 -345.0656434114751
初始化的聚类中心为: [162, 168]
第 0 次迭代后聚类中心为 335.8301886792453
第 1 次迭代后聚类中心为 368.93023255813955
第 2 次迭代后聚类中心为 411.030303030303
第 3 次迭代后聚类中心为 460.36
第 4 次迭代后聚类中心为 493.1904761904762
第 5 次迭代后聚类中心为 502.2
第 6 次迭代后聚类中心为 546.0625
第 7 次迭代后聚类中心为 613.6666666666666
第 8 次迭代后聚类中心为 634.5454545454545
第 9 次迭代后聚类中心为 634.5454545454545
{0: {'center': 174.82022471910113, 'values': [228, 202, 176, 149, 68, 199, 263, 248, 275, 384, 221, 110, 249, 260, 155, 188, 266, 245, 109, 345, 347, 327, 0, 0, 91, 344, 110, 148, 147, 194, 100, 0, 329, 37, 40, 198, 110, 150, 102, 144, 190, 208, 241, 286, 66, 97, 222, 88, 326, 98, 255, 89, 269, 162, 84, 157, 224, 230, 100, 158, 325, 133, 212, 168, 138, 119, 238, 77, 66, 118, 86, 139, 91, 116, 233, 87, 46, 223, 313, 240, 143, 143, 292, 132, 337, 116, 44, 77, 299], 'sse': 752225.1235955056}, 1: {'center': 634.5454545454545, 'values': [458, 408, 711, 471, 854, 1360, 494, 565, 467, 753, 439], 'sse': 794458.7272727273}}
"""