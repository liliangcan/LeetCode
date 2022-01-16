class Solution {
public:
    char findTheDifference(string s, string t) {
        //两个字符串 s 和 t，只包含小写字母
        vector<int> temp(26);
        for (auto& ch : s) {
            temp[ch - 'a']++;
        }
        for (auto& ch : t) {
            temp[ch - 'a']--;
            //当出现小于0的情况，说明这是多出来的那一个，返回ch即可
            if (temp[ch - 'a'] < 0) {
                return ch;
            }
        }
    return ' ';
    }
};
