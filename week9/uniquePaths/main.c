class Solution {
public:
    int uniquePaths(int m, int n) {
        //动态规划的做法
        // vector<vector<int>> f(m, vector<int>(n));
        // for (int i = 0; i < m; ++i) {
        //     f[i][0] = 1;
        // }
        // for (int j = 0; j < n; ++j) {
        //     f[0][j] = 1;
        // }
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         f[i][j] = f[i - 1][j] + f[i][j - 1];
        //     }
        // }
        // return f[m - 1][n - 1];

        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;          //组合数C的公式
        }
        return ans;

    }
};
