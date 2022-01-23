class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0,length = 0;
        int pre = 0;
        for(int n : nums){
            //若大于之前的数，就length++
            if(n > pre){
                length++;
            }else{
                //否者回归1
                length = 1;
            }
            //随时更新ans
            if(length > ans){
                ans = length;
            }
            //每一次都更新一下pre的值
            pre = n;
        }
        return ans;

    }
};
