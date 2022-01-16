class Solution {
public:
    int arrangeCoins(int n) {
        //解方程
        int temp = (sqrt((long long)8*n + 1) - 1) / 2;
        return temp;

    }
};
