class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j,length,count;
        char tmp;
        if (!strs.size()) {                 //向量里无字符串直接返回""
            return "";
        }
        length = strs[0].size();
        count = strs.size();
        for (i = 0; i < length; ++i) {      //i在一个字符串中从左向右走
            tmp = strs[0][i];               //tmp存放当前的单个字符
            for (j = 1; j < count; ++j) {           //j在向量中从上往下走
                if (i == strs[j].size() || strs[j][i] != tmp) {     //比较同一列位置的单个字符是否一致
                    return strs[0].substr(0, i);                    //不一致返回当前的最长公共子串
                }
            }
        }
        return strs[0];             //全部遍历完说明第一个字符串就是最长公共子串
    }
};
