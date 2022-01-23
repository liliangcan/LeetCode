class Solution {
public:
    // void reverseString(int left, int right, string& s){
    //     for(int i = left, j = right; i < j; i++,j--){
    //         swap(s[i], s[j]);
    //     }
    // }
    string reverseStr(string s, int k) {
        int n = s.length();
        //每次下标移动2k，并反转前k个
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
            // reverseString(i,min(i+k-1,n-1),s);   //可以运行，但慢
        }
        return s;
    }
};
