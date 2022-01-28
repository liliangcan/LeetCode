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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q1,q2;     //定义两个队列
        //若根节点不为空，将其加入q1中
        if(root){
            q1.push(root);
        }
        //大循环条件跟小循环相等，但是因为会在小循环外交换q1，q2，所以有各自的意义
        //大循环是判断，如果此时为空，确定没有下一层
        //小循环是判断，是否把当前层的元素都加入到an中
        while(!q1.empty()){
            //定义存储q1中也即当前层次的所有元素，最后需要加入到ans中
            vector<int> an;
            //只要q1不为空，就不断提取元素加入an
            while(!q1.empty()){
                TreeNode* temp = q1.front();
                q1.pop();
                an.push_back(temp->val);
                //同时将下一层入队q2
                if(temp->left){
                    q2.push(temp->left);
                }
                if(temp->right){
                    q2.push(temp->right);
                }
            }
            ans.push_back(an);
            swap(q1,q2);        //交换此时的q1和q2
        }
        return ans;

    }
};
