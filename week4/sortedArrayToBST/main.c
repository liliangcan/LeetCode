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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArray(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArray(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;       // 选择中间位置左边的数字作为根节点
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArray(nums, left, mid - 1);
        root->right = sortedArray(nums, mid + 1, right);
        return root;
    }
};
