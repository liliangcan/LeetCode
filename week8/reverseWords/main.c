class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        for(int i = 0; i < length; i++){
            if(s[i] != ' '){
                int left = i;
                for(i = i + 1; i <= length; i++){
                //下面的写法会导致还没反转最后一个单词就结束程序
                // for(i = i+1; i < length; i++){
                    // if(s[i] == ' '){
                    if(s[i] == ' ' || i ==length){
                        reverse(s.begin() + left, s.begin() + i);
                        break;
                    }
                }

            }
        }
        return s;
    }
};
