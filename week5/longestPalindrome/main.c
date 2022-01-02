class Solution {
public:    
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {   //扩展回文
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            //若符合扩展条件，则左右都改变一位
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);         //回文出现的可能两种情况，一种奇数位
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);     //一种偶数位
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
