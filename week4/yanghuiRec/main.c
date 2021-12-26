class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yanghui(numRows);
        for (int i = 0; i < numRows; ++i) {
            yanghui[i].resize(i + 1);
            yanghui[i][0] = yanghui[i][i] = 1;          //设置初始几行值
            for (int j = 1; j < i; ++j) {
                yanghui[i][j] = yanghui[i - 1][j] + yanghui[i - 1][j - 1];
            }
        }
        return yanghui;
    }
};
