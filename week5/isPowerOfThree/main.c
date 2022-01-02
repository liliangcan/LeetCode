class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;           //先排除等于0的特殊情况
        }
        while(n != 1){              //循环条件n!=0
            if(n%3!=0){             //当n模3不等于0说明除不尽，返回false
                return false;
            }
            n /= 3;                 //进行迭代
        }
        return true;                //到最后等于1，说明是3的幂次
    }
};
