class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            temp |= (n & 1) << (31 - i);            //取最后一位再向左移位，不断循环，再相加
            n >>= 1;                            //n自身右移，实现颠倒
        }
        return temp;      
    }
};
