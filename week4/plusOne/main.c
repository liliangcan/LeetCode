class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i,length = digits.size();
        for(i = length - 1;i >= 0; i--){
            if(digits[i] == 9){             //当位置为9时就清0，然后进位
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
                
        }
        vector<int> tmp(length + 1);    //若全为9则需要返回一个新数组
        tmp[0] = 1;
        return tmp;
    }
};
