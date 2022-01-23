class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //找到最小的两个数和最大的三个数
        //因为只有两种可能：两个最小的负数和一个最大的正数相乘；三个最大的正数相乘
        int firstMin = INT_MAX, secondMin = INT_MAX;
        int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
        for(int n : nums){
            if(n < firstMin){
                secondMin = firstMin;
                firstMin = n;
            }else if(n < secondMin){
                secondMin = n;
            }
            if(n > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = n;
            }else if(n > secondMax){
                thirdMax = secondMax;
                secondMax = n;
            }else if(n > thirdMax){
                thirdMax = n;
            }
        }
        return max(firstMin*secondMin*firstMax,firstMax*secondMax*thirdMax);
    }
};
