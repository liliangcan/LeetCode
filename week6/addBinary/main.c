class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        //设置循环次数和进位标志
        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; i++) {
            if(i < a.size()){
                carry += a.at(i)=='1';
            }
            if(i < b.size()){
                carry += b.at(i)=='1';
            }
            //判断此时的carry和，确定当前位置的数
            ans.push_back((carry % 2)?'1':'0');
            //然后carry恢为进位标志
            carry /= 2;
        }
        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
