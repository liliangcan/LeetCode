class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> countbits(n+1);
        int highBit = 0;                //设置最高有效位初始值为0
        for (int i=1;i<=n;i++) {
            if ((i & (i-1)) == 0) {
                highBit = i;            //当为2的整数次幂时更新最高有效位
            }
            countbits[i] = countbits[i-highBit] + 1;    //用前面已有的数计算countbits[i]
        }
        return countbits;
    }
};
