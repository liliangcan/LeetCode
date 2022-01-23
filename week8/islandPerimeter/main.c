class Solution {
    //分别用来表示下、右、上、左，四个邻边格子
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                //当前格子是陆地才进行下面的判断，若不是则直接跳过
                if (grid[i][j]) {
                    for (int k = 0; k < 4; ++k) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        //当是临界处或邻边为水域时，岛屿周长贡献值加一
                        if (tx < 0 || tx >= row || ty < 0 || ty >= col || !grid[tx][ty]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
