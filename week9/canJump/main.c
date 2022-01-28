class Solution {
public:
    bool canJump(vector<int>& nums) {
        // for(int i = 0; i < nums.size();){
        //     if(i == nums.size()-1){
        //         return true;
        //     }
        //     int maxSteps = nums[i];
        //     int temp = maxSteps;
        //     while(i+temp < nums.size() && nums[i+temp] == 0 && (i+temp) != nums.size()-1 && temp > 0){
        //         temp--;
        //     }
        //     if(maxSteps == 0){
        //         return false;
        //     }
        //     i += temp;
        // }
        // return true;

        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            //当前只有rightmost及以前的位置是可达的
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        //遍历完数组都没有到最后一个位置，就返回false
        return false;
    }
};
