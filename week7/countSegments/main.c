class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            //当前位置不为空，且“是第一位或前一位是空”，count++
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                count++;
            }
        }
        return count;
    }
};
