class Solution {
public:
    bool judgeCircle(string moves) {
        int temp = 0;
        //分别设置往各个方向走时temp的变化，左右抵消，上下抵消
        for(auto m : moves){
            if(m == 'U'){
                temp += 10;
            }else if(m == 'D'){
                temp -= 10;
            }else if(m == 'R'){
                temp += 1;
            }else if(m == 'L'){
                temp -= 1;
            }
        }
        return temp == 0;

    }
};
