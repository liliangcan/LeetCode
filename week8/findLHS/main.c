class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto n : nums){
            count[n]++;
        }
        int ans = 0;
        for (auto [key, val] : count) {
            if (count.count(key + 1)) {
                //一次遍历中不断替换最大的选择
                ans = max(ans, val + count[key + 1]);
            }
        }
        return ans;
    }
};
