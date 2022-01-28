class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
    
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int index){
        if (index == candidates.size()) {
            return;
        }
        //刚进入这个函数时用不到，但是在之后的调用用来判断什么时候将combine加入ans
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        //通过这一步一直走到index = candidates.size，再回退一步到size-1
        dfs(candidates, target, ans, combine, index + 1);
        //选择当前数
        if (target - candidates[index] >= 0) {
            combine.emplace_back(candidates[index]);
            //改变当前target值，递归调用dfs
            dfs(candidates, target - candidates[index], ans, combine, index);
            //回溯一个位置
            combine.pop_back();
        }
    }
};
