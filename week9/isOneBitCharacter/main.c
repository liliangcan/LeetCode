class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag = true;
        int n = bits.size();
        //若倒数第二个是0，或者只有一个数，则一定符合
        if(n == 1 || bits[n-2] == 0){
            return true;
        }
        for(int i = 0; i < n-1; i++){
            //若出现一对中的第一个1，就改变flag
            if(bits[i] == 1 && flag == true){
                flag = false;
            }else if(flag == false){
                //若出现一对中的第二个数，就恢复flag
                flag = true;
            }
        }
        return flag;
    }
};
