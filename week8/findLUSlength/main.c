class Solution {
public:
    int findLUSlength(string a, string b) {
        //首先判断两个字符串是否相等，如果相等，则说明没有特殊子序列
        if (a == b)
            return -1;
        //若不相等，则最大的那个序列长度就是结果
        //包含两种情况，等长不相等，不等长，都是同样的结果
        return max(a.length(), b.length());
    }
};
