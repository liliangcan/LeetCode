class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {         //首先判断两个单词长度是否相等，若不等直接返回false
            return false;
        }
        vector<int> temp(26, 0);
        for (auto& ch: s) {                     //分别记录连个单词字母出现的次数
            temp[ch - 'a']++;
        }
        for (auto& ch: t) {                     //在第二个单词中减去
            temp[ch - 'a']--;  
        }
        for(int i = 0;i<26;i++){
            if (temp[i] != 0) {                 //若出现一个最后结果不为0的位置，说明false
                return false;
            }
        }
        return true;
    }
};
