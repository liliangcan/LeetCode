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
    //不明白为什么用向量存储元素不行
    void flatten(TreeNode* root) {
        TreeNode* t;
        vector<TreeNode*> temp;
        // vector<int> temp;
        pre(root,temp);     //先前序存储到一个向量中
        //若root不为空，也即size大于0，开始构造新的树
        if(temp.size() > 0){
            t = temp[0];
            // t = new TreeNode(temp[0]);
            TreeNode* ans = t;
            for(int i = 1; i < temp.size(); i++){
                t->right = temp[i];
                // t->right = new TreeNode(temp[i]);
                t->left = nullptr;
                t = t->right;
            }
            root = ans;
        }
    }
    void pre(TreeNode* root,vector<TreeNode*>& temp){
        if(!root){
            return;
        }else{
            temp.push_back(root);
            // temp.push_back(root->val);
        }
        pre(root->left,temp);
        pre(root->right,temp);
    }
};
