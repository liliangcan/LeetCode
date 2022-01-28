class Solution {
public:
    int calculate(string s) {
        /*
        *目标结果是x+y
        *出现一个"A"，有x+y=(2x+y)+y=2x+2y
        *出现一个"B"，有x+y=x+(2y+x)=2x+2y
        *所以每出现一个A/B，都使x+y的值翻倍
        */
        if(!s.size()){
            return 1;
        }else{
            return 1<<s.size();
        }
        // int x = 1, y = 0;
        // for(auto ss : s){
        //     if(ss == 'A'){
        //         x = 2*x + y;
        //     }else if(ss == 'B'){
        //         y = 2*y + x;
        //     }
        // }
        // return x+y;
    }
};
