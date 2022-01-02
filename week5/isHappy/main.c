class Solution {
public:
    int bitSquareSum(int n) {               //求每位数的平方和
        int sum = 0;
        while(n > 0)                //循环条件n>0
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }   
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);          //慢指针走一步
            fast = bitSquareSum(fast);          //快指针走两步
            fast = bitSquareSum(fast);
        }while(slow != fast);               //当出现循环就跳出
        return slow == 1;                   //此时判断是否为一
    }
};
