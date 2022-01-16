class Solution {
public:
    int addDigits(int num) {
        int temp = 0;
        while(num > 9){
            while(num){
                //temp暂时存放各个位之和
                temp += num % 10;
                num /= 10;
            }
            num = temp;
            temp = 0;   //将temp重置为0
        }
        return num;
    }
};
