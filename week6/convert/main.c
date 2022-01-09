class Solution {
public:
    string convert(string s, int numRows) {
        //当只有一行时，则无改变
        if (numRows == 1){
            return s;
        }
        //确定实际的行数
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            //每当到了第一行或者最后一行就需要转换方向
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
