class Solution {
public:
    int climbStairs(int n) {
        if(n<=0){ return 0; }       //输入值非法时返回0
        if(n == 1){
            return 1;       //当n=1,2时为基准情况
        }else if(n == 2){
            return 2;
        }else{
            int first = 1,second = 2;       //先保存基准情况值
            int val = 0;                //初始val为0
            for(int i=3;i<=n;i++){      //当n>=3时，不断用前两项相加得到val
                val = first + second;
                first = second;
                second = val;
            }
            return val;         //返回val
        }
    }
};
