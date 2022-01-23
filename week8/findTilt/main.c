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
    int ans = 0;
    //生成一个节点之和的伴生树
    TreeNode* toSum(TreeNode* root){
        if(root){
            if(root->left == nullptr && root->right == nullptr){
                return root;
            }else if(root->left == nullptr){
                root->right = toSum(root->right);
                root->val += root->right->val;
            }else if(root->right == nullptr){
                root->left = toSum(root->left);
                root->val += root->left->val;
            }else{
                root->right = toSum(root->right);
                root->left = toSum(root->left);
                root->val += root->left->val + root->right->val;
            }
        }
        return root;
    }
    //取当前节点的值
    // int nodeVal(TreeNode* root){
    //     if(root == nullptr){
    //         return 0;
    //     }else{
    //         return root->val;
    //     }
    // }
    void startTilt(TreeNode* root){      //计算到此节点为止，坡度和的值
        if(root){
            int left,right;
            if(root->left != nullptr){
                left = root->left->val;
            }else{
                left = 0;
            }
            if(root->right != nullptr){
                right = root->right->val;
            }else{
                right = 0;
            }
            // int left = nodeVal(root->left),right = nodeVal(root->right);
            ans += abs(left - right);
            startTilt(root->left);
            startTilt(root->right);
        }
    }
    int findTilt(TreeNode* root) {
        root = toSum(root);     //先计算伴生树
        startTilt(root);        //再前序遍历伴生树，计算坡度
        return ans;
    }

    // int ans = 0;

    // int findTilt(TreeNode* root) {
    //     dfs(root);
    //     return ans;
    // }

    // int dfs(TreeNode* node) {
    //     if (node == nullptr) {
    //         return 0;
    //     }
    //     int sumLeft = dfs(node->left);
    //     int sumRight = dfs(node->right);
    //     ans += abs(sumLeft - sumRight);
    //     return sumLeft + sumRight + node->val;
    // } 

};
