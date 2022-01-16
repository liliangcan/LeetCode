class Solution {
public:
    bool isPowerOfFour(int n) {
        //一点点数学原理：4的幂mod3=1
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
