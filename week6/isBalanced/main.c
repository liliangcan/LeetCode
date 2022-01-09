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
    //计算当前节点为根节点的数的高度
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            //当前树的高度满足条件和两个子树都平衡说明整棵树平衡
            return abs(height(root->left)-height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
