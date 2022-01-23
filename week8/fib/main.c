class Solution {
public:
    int fib(int n) {
        int temp,first = 0,second = 1;
        if(n <= 1){
            return n;
        }
        for(int i = 1; i < n; i++){
            temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }
};
