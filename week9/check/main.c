class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        //若当前 格子元素不符合，返回false
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {   //若word中已经访问完了，直接返回true
            return true;
        }
        visited[i][j] = true;   //将此位置的元素标记为使用过
        //定义右，左，下，上四个方向
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;    //初始result设置成false
        //不断寻找邻边格子的元素
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            //限制邻边元素的合理范围
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    //检查邻边的元素是否符合剩下来的匹配
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        //如果符合，返回true结束
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;      //恢复此位置的元素标记
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        //定义一个跟网格等大小的二维向量，用来记录元素是否被访问过
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
