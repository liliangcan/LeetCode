class Solution {
public:
    //设置删除标志，出现一次需要删除的时候，flag就变成true，再一次出现需要删除的时候，就直接返回false
    bool flag = false;
    //给定字符串的左边界和右边界，判断是否是回文串
    bool palindrome(string s,int left,int right){
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            if(s[left] != s[right]){
                if(flag){
                    return false;
                }
                flag = true;
                //此处分别选择左边指针跳一格和右边指针跳一格，继续判断剩下的是否是回文串
                return palindrome(s,left,right-1) || palindrome(s,left+1,right);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        return palindrome(s,left,right);
    }
};
