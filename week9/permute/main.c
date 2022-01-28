class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        //设置一个向量used，用来存放nums数组中元素是否已经使用过
        vector<bool> used = vector<bool>(nums.size());
        dfs(nums, path, res, used);
        return res;
    }

    void dfs(vector<int> nums, vector<int>& path, vector<vector<int>>& res, vector<bool>& used) {
        //当path的size等于nums的size，则加入res中并返回
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            //若当前元素已经用过，则continue
            if (used[i]){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;         //修改用过的元素的状态
            dfs(nums, path, res, used);
            path.pop_back();     //回溯
            used[i] = false;        //回溯一步后，也恢复这个元素的状态
        }
    }
};
