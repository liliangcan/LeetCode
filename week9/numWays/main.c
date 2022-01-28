class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> temp(k + 1, vector<int>(n));
        temp[0][0] = 1;
        for (int i = 0; i < k; i++) {
            for (auto r : relation) {
                //找到起始点和目的点
                int src = r[0], dst = r[1];
                //更新i+1步到达dst的方法数
                temp[i + 1][dst] += temp[i][src];
            }
        }
        return temp[k][n - 1];
    }
};
