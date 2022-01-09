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
    int minDepth(TreeNode* root) {
        //当树为空时，最小深度为0
        if (root == nullptr) {
            return 0;
        }else if (root->left == nullptr && root->right == nullptr) {
            //当只有一个根节点即左右子树皆为空，则最小深度为1
            return 1;
        }
        int min_depth = INT_MAX;
        //使用递归分别求出左右子树的最小深度
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        //返回左右子树的最小深度+1
        return min_depth + 1;
    }
};
