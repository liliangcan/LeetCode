class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if (currColor == newColor) {    //若已经是这个颜色，则直接返回
            return image;
        }
        int row = image.size(), col = image[0].size();
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!q.empty()) {    //层次晕染
            int x = q.front().first, y = q.front().second;
            q.pop();
            //分别检查四个方向的颜色
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < row && my >= 0 && my < col && image[mx][my] == currColor) {
                    q.emplace(mx, my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
};
