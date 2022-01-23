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
    string tree2str(TreeNode* root) {
        //如果根节点为空，返回括号
        if(root == NULL){
            return "()";
        }
        //如果根节点不空，左右为空，则返回根节点即可。
        if(root->left == NULL && root->right == NULL){
            return "" + to_string(root->val);
        }
        //如果左空，右不空，则返回根节点+（）+（右边）
        if(root->left == NULL && root->right != NULL) {
            return "" + to_string(root->val) + "()" + "(" +tree2str(root->right) + ")";
        }
        //如果左不空，右空，则返回根节点+（左边）
        if(root->left != NULL && root->right == NULL) {
            return "" + to_string(root->val) + "(" +tree2str(root->left) + ")";
        }
        //如果左右都不空，则返回根节点+（左边）+（右边）
        return "" + to_string(root->val) + "(" + tree2str(root->left) + ")("+ tree2str(root->right) + ")";
    }
};
