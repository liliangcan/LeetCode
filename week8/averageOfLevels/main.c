/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> counts;
        vector<double> sums;
        dfs(root, 0, counts, sums);
        vector<double> averages;
        for (int i = 0; i < sums.size(); i++) {
            averages.emplace_back(sums[i] / counts[i]);
        }
        return averages;
    }
    void dfs(TreeNode* root, int level, vector<int> &counts, vector<double> &sums) {
        if (root == nullptr) {
            return;
        }
        //level是跟数组下标对齐，从0开始，所以永远比当前层数少1，刚好可以用来判断这一层是否已经开始记录
        //若才开始每一层的第一个元素，则sum这个数组的当前size是已经记录过的上面的层数，刚好等于level
        if (level < sums.size()) {
            //此处就是指当记录每一层除第一个元素以外的时候
            sums[level] += root->val;
            counts[level] += 1;
        } else {
            //此处就是指当记录每一层的第一个元素的时候
            sums.emplace_back(1.0 * root->val);
            counts.emplace_back(1);
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
};
