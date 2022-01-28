class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            //选取不同的元素作为左右子树的根节点
            for (int j = 1; j <= i; ++j) {
                //分别是左子树的可能情况和右子树的可能情况，然后相乘
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
