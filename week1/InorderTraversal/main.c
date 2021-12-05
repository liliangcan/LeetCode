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
    void mainTraversal(TreeNode* root, vector<int>& inordercout) {
        if (root) {
            mainTraversal(root->left, inordercout);
            inordercout.push_back(root->val);
            mainTraversal(root->right, inordercout);
        }   
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inordercout;        //定义一个存放中序遍历返回值的向量
        mainTraversal(root, inordercout);
        return inordercout;
    }
};
