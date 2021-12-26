class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (char ch: s) {
            if (isalnum(ch)) {          //若符合就加到tmp
                tmp += tolower(ch);
            }
        }
        int n = tmp.size();
        int left = 0, right = n - 1;            //利用双指针分别从左和右进行比较
        while (left < right) {
           if (tmp[left] != tmp[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
