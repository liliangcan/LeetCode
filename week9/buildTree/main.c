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
    //构造哈希表，反向映射inorder中对应根节点的位置，帮助我们快速定位根节点
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;      //反向映射
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                        int pLeft, int pRight, int iLeft, int iRight) {
        //若左下标大于右下标，则直接返回nullptr
        if (pLeft > pRight) {
            return nullptr;
        }
        int pRoot = pLeft;      //前序遍历中的第一个节点就是根节点
        int iRoot = index[preorder[pRoot]];     //在中序遍历中定位根节点的下标
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[pRoot]);
        // 得到左子树中的节点数目
        int size_left_subtree = iRoot - iLeft;
        // 递归地构造左子树，并连接到根节点
        root->left = myBuildTree(preorder, inorder, pLeft + 1, pLeft + size_left_subtree, iLeft, iRoot - 1);
        // 递归地构造右子树，并连接到根节点
        root->right = myBuildTree(preorder, inorder, pLeft + size_left_subtree + 1, pRight, iRoot + 1, iRight);
        return root;
    }

};
