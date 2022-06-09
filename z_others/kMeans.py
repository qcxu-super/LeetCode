import numpy as np
import pandas as pd
import random

"""
常规kMeans
1.随机初始化k个聚类中心
2.按照距离最近原则，将每条数据都划分到最近的簇类
3.第一次迭代后，更新每个簇类中心。然后根据新的簇类镇中心，依然按照最近原则，进行第二次数据归类
4.直到簇类中心不再改变，或者前后变化小于误差范围，或者达到最大迭代次数，停止迭代
"""

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
    cluster = km.kMeans(newData['price'].values, K=3, maxIters = 10)
    print(cluster)


"""
最大异常值为 5000, 最小异常值为 -345.0656434114751
初始化的聚类中心为: [241, 753, 89]
第 0 次迭代后聚类中心为 100.85106382978724
第 1 次迭代后聚类中心为 107.09803921568627
第 2 次迭代后聚类中心为 113.72727272727273
第 3 次迭代后聚类中心为 115.41071428571429
第 4 次迭代后聚类中心为 117.10526315789474
第 5 次迭代后聚类中心为 117.10526315789474
{0: {'center': 312.46153846153845, 'values': [228, 263, 248, 275, 384, 221, 458, 249, 260, 408, 266, 245, 345, 471, 347, 327, 344, 329, 241, 286, 222, 326, 494, 255, 269, 224, 565, 230, 325, 238, 467, 233, 223, 313, 240, 292, 337, 299, 439]}, 1: {'center': 919.5, 'values': [711, 854, 1360, 753]}, 2: {'center': 117.10526315789474, 'values': [202, 176, 149, 68, 199, 110, 155, 188, 109, 0, 0, 91, 110, 148, 147, 194, 100, 0, 37, 40, 198, 110, 150, 102, 144, 190, 208, 66, 97, 88, 98, 89, 162, 84, 157, 100, 158, 133, 212, 168, 138, 119, 77, 66, 118, 86, 139, 91, 116, 87, 46, 143, 143, 132, 116, 44, 77]}}
"""