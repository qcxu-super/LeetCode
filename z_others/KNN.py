#!/usr/bin/python
# -*- coding: utf-8 -*-

import os, sys
import numpy as np
import collections

class KNN:
    def __init__(self, k):
        self.K = k
    
    def createData(self):
        '''
        准备数据
        身高  体重  性别
        180   76    男
        158   43    女
        176   78    男
        161   49    女
        '''
        features = np.array([[180,76],[158,43],[176,78],[161,49]])
        labels = ["男", "女", "男", "女"]
        return features, labels
    

    def Normalization(self, data):
        '''
        归一化
        '''
        maxs = np.max(data, axis=0)
        mins = np.min(data, axis=0)
        new_data = (data - mins) / (maxs - mins)
        return new_data, maxs, mins
    

    def classify(self, one, data, labels):
        '''
        knn
        '''
        # 计算测试样本与每个训练样本的距离。这里用欧式距离
        differenceData = data - one
        squareData = (differenceData ** 2).sum(axis = 1)
        distance = squareData ** 0.5
        sortDistanceIndex = np.argsort(distance, axis=-1)
#         print(sortDistanceIndex) # [0.18181818 1.24835936 0.05714286 1.02955237] -> [2 0 3 1]

        sorted_labels = labels[sortDistanceIndex] # ['男' '男' '女' '女']
        topK_labels = sorted_labels[:self.K]
        predict_label = collections.Counter(topK_labels).most_common(1) # [('男', 2)]
        return predict_label[0][0]


if __name__ == '__main__':
    knn = KNN(3)
    features, labels = knn.createData()
    new_data, maxs, mins = knn.Normalization(features)
    test = np.array([176,76])
    new_test = (test - mins) / (maxs - mins)
    result = knn.classify(new_test, new_data, np.array(labels))
    print("数据 {} 的预测性别为: {}".format(test, result))