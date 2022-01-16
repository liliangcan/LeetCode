class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            //判断条件一定要注意顺序，若没有先判断是否到达边界，会导致数组下标越界异常
            if (i+1 == nums.size() || nums[i]+1 != nums[i+1]) {
                //若满足条件，则说明当前的小区间结束
                ans.push_back(to_string(nums[left]) + 
                    (left == i ? "" : ("->" + to_string(nums[i]))));
                left = i+1;         //开始新的小区间，重新设置左边界值
            }
        }
        return ans;
    }
};
