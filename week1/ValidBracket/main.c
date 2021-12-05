class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1){return false;}    //若字符串的长度为奇数直接返回false
        unordered_map<char, char> pairs = { {')', '('},{']', '['},{'}', '{'} };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {         //当对应的左括号存在时值为1，则继续往下执行
                if (stk.empty() || stk.top() != pairs[ch]) { return false; }
                //若栈为空或者栈顶不是对应的括号，返回false
                stk.pop();      //弹出栈顶元素
            }
            else { stk.push(ch); }
        }
        return stk.empty();     //若最后栈空，说明为有效括号，返回true
    }
};
