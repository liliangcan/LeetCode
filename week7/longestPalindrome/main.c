class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        //先统计每个字符出现的次数
        for (char c : s)
            count[c]++;
        //根据每个字符出现的次数，取其中的最大偶数为可用长度
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
        }
        //若ans小于，则说明最少有一个可用的奇数状态，就返回++ans
        if(ans < s.length()){
            return ++ans;
        }else{
            return ans;
        }
    }
};
