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
    void dfs(TreeNode* root, int& pre, int& ans) {
        //如果为空就直接返回
        if (root == nullptr) {
            return;
        }
        //开始进行中序遍历
        dfs(root->left, pre, ans);
        //因为是二叉搜索树，所以有一定的顺序
        //最小的差值只会在父子节点之间，所以只需要比较相邻之间元素值就可以
        if (pre == -1) {
            //若当前节点是根节点，则只需记录pre值就继续下面的执行操作
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};
