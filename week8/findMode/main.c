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
    vector<int> answer;
    // int base, count;
    int maxCount = 0;
    unordered_map<int,int> hashMap;
    //更新当前这个元素的计数值，若大于等于maxCount，则加入answer
    void update(int x) {
        hashMap[x]++;
        if(hashMap[x] == maxCount){
            answer.emplace_back(x);
        }
        if(hashMap[x] > maxCount){
            maxCount = hashMap[x];
            answer = vector<int> {x};
        }
        // if (x == base) {
        //     ++count;
        // } else {
        //     count = 1;
        //     base = x;
        // }
        // if (count == maxCount) {
        //     answer.push_back(base);
        // }
        // if (count > maxCount) {
        //     maxCount = count;
        //     answer = vector<int> {base};
        // }
    }

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        update(o->val);
        dfs(o->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
