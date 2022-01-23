class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0,maxcount = 0;
        for(int i = 0;i<nums.size();i++){
            //若等于1，count++
            if(nums[i] == 1){
                count++;
            }else if(maxcount < count){ //否则若maxcount小于count，就更新maxcount
                maxcount = count;       //再重置count为0
                count = 0;
            }else{
                count = 0;          //否则直接重置count为0
            }
        }
        if(maxcount < count){       //结束时需要再判断一下
                maxcount = count;
        }
        return maxcount;
    }
};
