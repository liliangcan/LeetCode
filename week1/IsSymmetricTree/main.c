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
class Solution {                        //has something wrong
public:
    void InorderTraversal(TreeNode* root, vector<int>& inordercout) {
        if (root) {
            InorderTraversal(root->left, inordercout);
            inordercout.push_back(root->val);
            InorderTraversal(root->right, inordercout);
        }   
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>  inordercout;
        InorderTraversal(root,inordercout); //调用中序遍历，结果保存在向量inordercout中
        int i;
        int size = inordercout.size();
        for(i=0;i<size/2;i++){
            //比较左右对称位置的值是否一致，若不相同，则返回false
            if(inordercout[i] != inordercout[size-i-1])
            return false;
        }
        return true;
    }
};

class Solution {                    //right
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v)   continue;
            if ((!u || !v) || (u->val != v->val)) return false;
            q.push(u->left); q.push(v->right);
            q.push(u->right); q.push(v->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
