class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch: s) {
            ++frequency[ch];            //当出现时就加入map表
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {         //从字符串遍历。找到第一个map中值为1的
                return i;
            }
        }
        return -1;
    }
};
