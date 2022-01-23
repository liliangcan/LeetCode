class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0, n = s.size(), last = 0, ans = 0;
        while (i < n) {
            char c = s[i];
            int count = 0;
            //统计每次相同的的1或者0有几个
            while (i < n && s[i] == c) {
                i++;
                count++;
            }
            //每次都加上这一次循环能得到的组数
            ans += min(count, last);
            last = count;       //下一次循环前记录当前这一段1或者0的数量
        }
        return ans;
    }
};
