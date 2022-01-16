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
    //判断是否为叶子节点，方便下面函数的调用
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //若为空，则返回0
        if(root == nullptr){
            return 0;
        }else{
            int sum = 0;
            if (root->left) {
                //若左节点是叶子节点，则加上val，否则继续求它的左叶子节点之和
                sum += isLeafNode(root->left) ? root->left->val : sumOfLeftLeaves(root->left);
            }
            //若右节点存在且不是叶子节点，则继续求它的左叶子节点之和
            if (root->right && !isLeafNode(root->right)) {
                sum += sumOfLeftLeaves(root->right);
            }
            return sum;
        }
    }
};
