class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 1024; ++i) {
            // 用位运算取出高4位h 和低6位m
            int h = i>>6, m = i&63;
            //当h<12,m<60，并且二进制形式的1的个数与turnedOn相等
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};
