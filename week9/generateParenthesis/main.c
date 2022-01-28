class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        //当字符串长度已经等于2n了，就加入ans并返回
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        //当左括号数量小于n时，加左括号
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            //每次结束都回溯一步
            cur.pop_back();
        }
        //当有括号少于左括号时，加右括号
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            //每次结束都回溯一步
            cur.pop_back();
        }
    }
};
