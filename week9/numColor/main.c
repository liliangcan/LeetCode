/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> myMap;
    int numColor(TreeNode* root) {
        dfs(root);
        int count = 0;
        for(int i = 0; i < myMap.size(); i++){
            if(myMap[i] > 0){   //若此颜色出现过，则count++
                count++;
            }
        }
        return count;
    }
    void dfs(TreeNode* root){
        if (!root) {
            return;
        }
        myMap[root->val]++; //对应的颜色++
        dfs(root->left);
        dfs(root->right);
    }
};
