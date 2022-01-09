class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            temp.clear();
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
