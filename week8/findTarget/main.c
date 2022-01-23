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
    void inorder(TreeNode* r,vector<int>& v){ // 递归法中序遍历
        if(r){
            inorder(r->left,v);
            v.emplace_back(r->val);
            inorder(r->right,v);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v); // 中序遍历BST得到升序数组
        for(int left = 0, right = v.size() - 1; left < right; ){ // 头尾指针
            if(v[left] + v[right] == k){ // 头指针元素+尾指针元素==目标数,返回找到
                return true;
            }
            else if(v[left] + v[right] < k){ // 头指针元素+尾指针元素<目标数，头指针后移
                left++;
            }
            else{ // 头指针元素+尾指针元素>目标数，尾指针前移
                right--;
            }
        }
        return false;
    }
};
