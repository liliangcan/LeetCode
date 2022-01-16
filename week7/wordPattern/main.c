class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = s.length();
        int i = 0;
        for (auto ch : pattern) {
            //若模板长于s，直接返回false
            if (i >= m) {
                return false;
            }
            int j = i;
            while (j < m && s[j] != ' ') j++;
            //找到每一个单词赋值到tmp
            const string &tmp = s.substr(i, j - i);
            //判断是否已经存在map表中，且是否出现矛盾
            if (str2ch.count(tmp) && str2ch[tmp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
            //加入map表
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;      //设置新的起点
        }
        //若模板短于s，返回false
        return i >= m;
    }
};
