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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty()) {
            TreeNode *now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            //因为每个节点可以有负数，所以此处不需要提前判断
            // if(temp > targetSum){
            //     continue;
            // }
            if (now->left == nullptr && now->right == nullptr) {
                if (temp == targetSum) {
                    //相等就说明已经找到，直接返回TRUE
                    return true;
                }
                //若不相等，则直接继续下一轮循环
                continue;
            }
            //若左子树存在，入队
            if (now->left != nullptr) {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            //若右子树存在，入队
            if (now->right != nullptr) {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        //最后循环结束说明无，返回false
        return false;
    }
};
