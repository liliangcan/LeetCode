class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^=y;                    //将x和y进行异或
        return __builtin_popcount(diff);        //返回异或结果二进制表示的1的个数
    }
};
