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
    int lenmax;                     //最长路径上的节点数
    int depth(TreeNode* tmp){
        if (tmp == NULL) {
            return 0;              // 访问到空节点了，返回0
        }
        int L = depth(tmp->left);          // 左儿子为根的子树的深度
        int R = depth(tmp->right);         // 右儿子为根的子树的深度
        lenmax = max(lenmax, L+R+1);         // 计算d_node即L+R+1 并更新lenmax
        return max(L,R)+1;              // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        lenmax = 1;
        depth(root);
        return lenmax-1;
    }
};
