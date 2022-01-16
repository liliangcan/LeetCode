class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        //不断选择可能的子串进行尝试，因为是重复子串，所以最长是一半大小
        for (int i = 1; i * 2 <= n; i++) {
            if (n % i == 0) {       //要求n一定是重复子串长度的整数倍
                bool match = true;
                for (int j = i; j < n; j++) {
                    //不断的按照这个周期比较相应位置的元素是否一致
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return match;
                }
            }
        }
        return false;
    }
};
