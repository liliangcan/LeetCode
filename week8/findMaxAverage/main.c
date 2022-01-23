class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currentMax = 0;
        for(int i = 0; i < k; i++) {
            currentMax += nums[i];
        }
        int maxSum = currentMax;
        //利用滚动窗口，不断改变currentMax并更新maxSum
        for(int i = 0,j = k; j < nums.size(); i++,j++){
            currentMax += nums[j] - nums[i];
            if(maxSum < currentMax){
                maxSum = currentMax;
            }
        }
        //double计算较慢，最后再改成double类型
        return (double)maxSum/k;
    }
};
