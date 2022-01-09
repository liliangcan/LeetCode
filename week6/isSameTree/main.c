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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //若都为空说明相同
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            //若其中一个为空说明不相同
            return false;
        } else if (p->val != q->val) {
            //若根节点不相同，则直接返回false
            return false;
        } else {
            //进行递归
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
