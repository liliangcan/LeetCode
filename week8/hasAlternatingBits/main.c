class Solution {
public:
    bool hasAlternatingBits(int n) {
        long m = (n>>1);        //先将n右移一位
        m ^= (long)n;       //然后再跟n异或，此时结果应该是全1
        //m再与m+1相与，如果为0 ，则说明是交替的
        return (m & (m+1)) == 0;
    }
};
