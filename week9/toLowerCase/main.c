class Solution {
public:
    string toLowerCase(string s) {
        //大写字母{A - Z}的ASCII 码范围为 [65, 90]：
        //小写字母{a - z}的ASCII 码范围为 [97, 122]。
        for (char& ch: s) {
            if (ch >= 65 && ch <= 90) {
                ch |= 32;
            }
        }
        return s;
    }
};
