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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        root->left = invertTree(root->left);        //递归左子树
        root->right = invertTree(root->right);      //递归右子树
        TreeNode* Tmp = root->left;             //交换左子树和右子树
        root->left = root->right;
        root->right = Tmp;
        return root;
    }
};
