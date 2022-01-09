class Solution {
public:
    bool isPalindrome(int x) {
        //首先排除特殊情况，负数不可能，不为零的个位数为0的数不可能
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while (x > revertedNumber) {
            //不断将x模10加上反转后的数乘以10得到新的的反转后的数，然后再将x除10
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        //因为有奇数位和偶数位的两种情况
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
