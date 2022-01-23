class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        //如果不合理，则直接输出原数组
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            //将原数组映射到新数组中
            ans[x / c][x % c] = mat[x / n][x % n];
        }
        return ans;
    }
};
