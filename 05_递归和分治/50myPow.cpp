/*
50. Pow(x, n)
https://leetcode-cn.com/problems/powx-n/

 */

class Solution {
   public:
    double myPow(double x, int n) {
        // int 范围：[-2^31, 2^31-1]
        if (n == -(1ll << 31))
            return 1.0 / (myPow(x, -(n + 1)) * x);
        if (n < 0)
            return 1.0 / myPow(x, -n);
        if (n == 0)
            return 1;

        double temp = myPow(x, n / 2);  // 向下取整
        if (n % 2 == 1)
            return temp * temp * x;
        else
            return temp * temp;
    }
};