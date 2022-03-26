# 1.基础题目

- [66. 加一 (easy)](https://leetcode-cn.com/problems/plus-one/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/66plusOne.cpp)


# 2.合并数组

- [88. 合并两个有序数组 (easy)](https://leetcode-cn.com/problems/merge-sorted-array/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/88merge.cpp)

# 3.保序filter

- [26. 删除有序数组中的重复项 (easy)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/26removeDuplicates.cpp)

- [283. 移动零 (easy)](https://leetcode-cn.com/problems/move-zeroes/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/283moveZeroes.cpp)

# 4.前缀和&差分

```
前缀和:s[i]=sum(0,i)=sum(0,i-1)+a[i]
--> 做差分计算字段和:sum(l,r)=sum(0,r)-sum(0,l-1)

二维前缀和：s[i][j]=sum(a[x][y])(x<=i,y<=j)=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]
--> 做差分计算以(p,q)为左上角、(i,j)为右下角的子矩阵和:sum(p,q,i,j)=s[i][j]-s[i][q-1]-s[p-1][j]+s[p-1][q-1]

差分:B[1]+B[2]+...+B[n]=(A[2]-A[1])+(A[3]-A[2])+...+(A[n]-A[n-1])=A[n]
--> 结论：差分数组B的前缀和，就是原数组A
--> 差分一般这样用：在计算给A的字段统一加一个数的时候，即A[l,r]+d，时间复杂度O(n)。但利用差分算，只要B[l]+d、B[r+1]-d，时间复杂度O(1)
```

- [1248. 统计「优美子数组」 (median)](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/1248numberOfSubarrays.cpp)

- [53. 最大子数组和 (easy)](https://leetcode-cn.com/problems/maximum-subarray/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/53maxSubArray.cpp)

- [303. 区域和检索 - 数组不可变 (easy)](hhttps://leetcode-cn.com/problems/range-sum-query-immutable/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/303NumArray.cpp)

- [304. 二维区域和检索 - 矩阵不可变 (median)](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/304NumMatrix.cpp)

- [1109. 航班预订统计 (median)](https://leetcode-cn.com/problems/corporate-flight-bookings/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/1109corpFlightBookings.cpp)

- [560. 和为 K 的子数组 (median)](https://leetcode-cn.com/problems/subarray-sum-equals-k/) |  [solution](https://github.com/qcxu-super/LeetCode/master/Leetcode/01_数组/560subarraySum.cpp)

