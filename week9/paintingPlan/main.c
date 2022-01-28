class Solution {
public:
    int paintingPlan(int n, int k) {
        if(k == 0 || n*n == k){
            return 1;
        }
        // int t = k/n;
        // if(t == n){
        //     return 1;
        // }
        // int s = k%n;
        // if(s == 0){
        //     return C(t,n)*2;
        // }
        // int temp = (s > 0 ? 1:0) + t;
        int ans = 0;
        // if((t + s) == n){       //此处判断有问题
        //     for(int i = 0; i <= t; i++){
        //         ans += C(i,n)*C(temp-i,n);
        //     }
        // }else{
        //     return 0;
        // }
        // return ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i*n + j*n - i*j == k){
                    ans += C(i,n)*C(j,n);
                }
            }
        }
        return ans;
    }
    int C(int c,int n){
        int num = 1;
        for(int i = n ; i > n-c ; i--){
            num *= i;
        }
        for(int i = 1 ; i <= c ; i++){
            num /= i;
        }
        return num;
    }
    // int C[6][6];
    // void Init(){
    //     for(int i = 0; i < 10; i++){
    //         for(int j = 0; j <= i; j++){
    //             if(!j){
    //                C[i][j] = 1; 
    //             }else {
    //                 C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    //             }
    //         }
    //     }
    // }
};
