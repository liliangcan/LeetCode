class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int ans = 0;
        for(;i < j; i++){
            //设置左边下标和右边下标
            //若右边下标对应的元素符合条件，则之间的元素都符合
            while(i < j && nums[i] + nums[j] > target){
                j--;
            }
            //一次性加上中间元素的数量进总方案数中
            ans += j - i;
            if(ans > 1000000007){
                ans %= 1000000007;
            }
        }
        return ans;
    }
};
