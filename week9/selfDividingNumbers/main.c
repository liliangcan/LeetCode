class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(check(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool check(int n){
        int num = n;
        int temp;
        while(n>0){
            //暂时存储最后一位
            temp = n%10;
            n /= 10;    //更新n
            if(temp == 0){      //自除数不包含0
                return false;
            }else if(num % temp != 0){  //不能整除
                return false;
            }
        }
        return true;
    }
};
