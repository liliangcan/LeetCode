class Solution {
public:
    bool checkRecord(string s) {
        int countL = 0, countA = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                countA++;
            }
            if(s[i] == 'L'){
                countL++;
            }else{
                countL = 0;
            }
            if(countA >= 2 || countL >= 3){
                return false;
            }
        }
        return true;
    }
};
