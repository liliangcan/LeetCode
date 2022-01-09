class Solution {
public:
    int lengthOfLastWord(string s) {
        //下标从最后一位开始，反向遍历
        int index = s.size() - 1;
        //当出现第一个不为空的字符开始奇计数
        while (s[index] == ' ') {
            index--;
        }
        //初始长度为0
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }
        return wordLength;
    }
};
