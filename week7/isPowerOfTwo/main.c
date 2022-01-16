class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int temp = 1;
        // while(temp <= n){
        //     if(temp == n){
        //         return true;
        //     }
        //     temp<<1;
        // }
        // return false;
        return n > 0 && (n & (n - 1)) == 0;
    }
};
