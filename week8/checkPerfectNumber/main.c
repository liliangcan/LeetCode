class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1){       //特殊判断1
            return false;
        }
        int sum = 1;
        for(int i=2; i<=sqrt(num); i++){
            if(num%i == 0){
                //分别加上i和num/i
                sum += i;
                sum += num/i;
            }
        }
        if(sum == num){
            return true;
        }else{
            return false;
        }
        // int sum = 0;
        // for(int i=1; i<=num/2; i++){
        //     if(num%i == 0){
        //         sum += i;
        //     }
        // }
        // if(sum == num){
        //     return true;
        // }else{
        //     return false;
        // }
    }
};
