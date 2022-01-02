class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> temp(n);
        for(int i = 0;i < n;i++) temp[i] = to_string(i+1);      //转换成string型
        for(int i = 3;i <= n; i+=3) temp[i-1] = "Fizz";         //覆盖掉3的倍数的
        for(int i = 5;i <= n; i+=5) temp[i-1] = "Buzz";         //覆盖掉5的倍数的
        for(int i = 15;i <= n;i+=15) temp[i-1] = "FizzBuzz";    //覆盖掉15的倍数的
        return temp;
    }
};
