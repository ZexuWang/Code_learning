/*43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
 

提示：

1 <= num1.length, num2.length <= 200
num1 和 num2 只能由数字组成。
num1 和 num2 都不包含任何前导零，除了数字0本身。*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {//特别的case判断
            return "0";
        }

        int m = num1.size(), n = num2.size();
        vector<int> ans(m + n);//令m、n分别表示num1和num2的长度，那么两者乘积的长度在[m + n -1, m + n]区间内
        for (int i = m - 1; i >= 0; --i) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >=0; --j) {
                int y = num2[j] - '0';
                ans[i + j + 1] += x * y;//先将每一位的乘积暂时存在i+j+1的位置，为什么要放在这里呢？详解件草稿第一页
            }
        }

        for (int i = m + n - 1; i > 0; --i) {
            ans[i - 1] += ans[i] / 10;//进位
            ans[i] %= 10;//取余
        }

        int idx = ans[0] == 0 ? 1 : 0;//对最高位进行非0判断
        string res;
        while (idx < m + n) {
            res.push_back(ans[idx]);
            idx++;
        }
        for (auto& c : res) {
            c += '0';
        }
        return res;
    }
};
