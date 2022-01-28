class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int rows = grid.size(), cols = grid[0].size();
        // vector<vector<int>> temp(rows,vector<int>(cols,0));
        // return minSum(grid,0,0,temp);

        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector<vector<int>> (rows, vector<int>(columns));
        dp[0][0] = grid[0][0];
        //首先记录第一行第一列的路径和
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        //然后根据已有的不断记录每一个到每一个格子的路径和
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }

    // int minSum(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& temp){
    //     if(temp[x][y] != 0){        //使用部分动态规划，但还是超时
    //         return temp[x][y];
    //     }
    //     int row = grid.size()-x, col = grid[0].size()-y;    //计算已当前位置为起点的网格的大小
    //     if(row == 0 || col == 0){       //若为0，则直接返回0
    //         return 0;
    //     }
    //     int sum = 0;
    //     if(row == 1){       //若只有一行，则全部相加
    //         for(int i = y; i < grid[0].size(); i++){
    //             sum += grid[x][i];
    //         }
    //     }else if(col == 1){     //若只有一列，则全部相加
    //         for(int i = x; i < grid.size(); i++){
    //             sum += grid[i][y];
    //         }
    //     }else{
    //         int down = minSum(grid,x+1,y,temp);
    //         int right = minSum(grid,x,y+1,temp);
    //         return min(down, right) + grid[x][y];   //分别计算下一步的最小路径和
    //     }
    //     temp[x][y] = sum;   //记录当前位置的最小路径和
    //     return sum;
    // }
};
