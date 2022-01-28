class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //这一题似乎有一点点问题，比如（["z","a","b"] "z"）
        for(auto l : letters){
            //挨个比较
            if(l - target > 0){
                return l;
            }
        }
        //若没有比它大的，就返回第一个
        return letters[0];
    }
};
