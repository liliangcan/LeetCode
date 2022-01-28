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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        //使用中序遍历一遍二叉树
        dfs(root,inorder);
        //然后判断inorder里是否有不符合从小到大顺序的
        for(int i = 1; i < inorder.size(); i++){
            if(inorder[i] <= inorder[i-1]){
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* root,vector<int>& inorder){
        if(!root){
            return;
        }
        dfs(root->left,inorder);
        inorder.push_back(root->val);
        dfs(root->right,inorder);
    }
};
