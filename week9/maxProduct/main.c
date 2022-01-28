class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Max，Min 分别是当前位置以前的最大最小乘积
        int Max = nums[0], Min = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            //preMax，preMin 分别是前一个位置以前的最大最小乘积
            int preMax = Max, preMin = Min;
            Max = max(preMax * nums[i], max(nums[i], preMin * nums[i]));
            Min = min(preMin * nums[i], min(nums[i], preMax * nums[i]));
            ans = max(Max, ans);        //更新ans
        }
        return ans;
    }
};
