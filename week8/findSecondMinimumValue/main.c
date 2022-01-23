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
    int ans = -1;
    int rootvalue;
    int findSecondMinimumValue(TreeNode* root) {
        //根节点默认是最小的值
        rootvalue = root->val;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        //当ans已有值，且当前节点的值大于等于ans，说明不需要继续往下了
        //因为ans只会存储比根节点值大的数，也即第二小的值
        if (ans != -1 && node->val >= ans) {
            return;
        }
        //若当前节点的值小于ans，且大于根节点的值，就更新ans
        if (node->val > rootvalue) {
            ans = node->val;
        }
        dfs(node->left);
        dfs(node->right);
    }
};
