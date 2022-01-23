class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag1LowerCase = true,upperCase = false,lowerCse = false;
        if(word[0] != tolower(word[0])){
            flag1LowerCase = false;
        }
        for(int i = 1; i < word.size(); i++){
            //若第一位是小写，后面出现大写，则返回false
            if(flag1LowerCase && word[i] != tolower(word[i])){
                return false;
            }
            //若第一位是大写，则后面只能全是大写或全是小写
            if(flag1LowerCase == false){
                if(word[i] == tolower(word[i])){
                    lowerCse = true;
                }
                if(word[i] != tolower(word[i])){
                    upperCase = true;
                }
                //若大小写都出现了，则返回false
                if(lowerCse && upperCase){
                    return false;
                }
            }
        }
        return true;
    }
};
