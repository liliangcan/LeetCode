class Solution {
public:
    int reverse(int x) {
        int revertedNumber = 0;
        while (x != 0) {
            //判断溢出情况
            if (revertedNumber < INT_MIN / 10 || revertedNumber > INT_MAX / 10) {
                return 0;
            }
            revertedNumber = revertedNumber * 10 + x%10;
            x /= 10;
        }
        return revertedNumber;
    }
};
