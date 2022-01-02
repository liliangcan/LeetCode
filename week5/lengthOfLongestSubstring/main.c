class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> temp;        // 哈希集合，记录每个字符是否出现过
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                temp.erase(s[i - 1]);
            }
            while (rk + 1 < n && !temp.count(s[rk + 1])) {       // 不断地移动右指针                
                temp.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);         // 第 i 到 rk 个字符是一个极长的无重复字符子串
        }
        return ans;
    }
};
