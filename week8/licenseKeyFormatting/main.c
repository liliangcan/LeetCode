class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int count = 0;
        //因为是第一个组可以不是格式化，所以从最后开始遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            //提取出每一个不是-的字符
            if (s[i] != '-') {
                //首先判断是否已经有一组（k个）的数了，如果是加上-符号
                if (count > 0 && count % k == 0) {
                    ans.push_back('-');
                }
                //转换成大写并存进新字符串中
                ans.push_back(toupper(s[i]));
                count++;
                // if (count % k == 0) {
                //     ans.push_back('-');
                // }
            }
        }
        // if (ans.size() > 0 && ans.back() == '-') {
        //     ans.pop_back();
        // }
        reverse(ans.begin(), ans.end());        
        return ans;
    }
};
