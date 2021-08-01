class Solution {
public:

/*
解题思路：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/
*/
    double myPow(double x, int n) {
        long b = n;
        if(x == 0) return 0;
        double res = 1;
        if (b < 0) {
            x = 1/x;
            b = -b;//代码中 int32 变量 n \in [-2147483648, 2147483647]n∈[−2147483648,2147483647] ，因此当 n = -2147483648n=−2147483648 时执行 n = -nn=−n 会因越界而赋值出错。解决方法是先将 nn 存入 long 变量 bb ，后面用 bb 操作即可。
        }
        while (b != 0) {
            if (b % 2 == 1) {
                res *= x; 
            }
            x *= x;
            b = floor(b/2);
        }
    return res;
    }
};