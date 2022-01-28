class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //因为负数，所以此判断会报错，无需加上这个提前判断
            // if(2*sum > total){
            //     return -1;
            // }
            if (2 * sum + nums[i] == total) {   //若当前的sum符合以下条件，说明找到了中心点
                return i;
            }
            sum += nums[i];
        }
        return -1;

        // int leftSum = 0, rightSum = 0;
        // int i,j;
        // for(i = 0, j = nums.size()-1; i < j;i++,j-- ){
        //     leftSum += nums[i];
        //     rightSum += nums[j];
        //     if(leftSum < rightSum){
        //         i++;
        //         leftSum += nums[i];
        //     }else if(leftSum > rightSum){
        //         j--;
        //         rightSum += nums[j];
        //     }
        // }
        // if(leftSum != rightSum || i > j){
        //     return -1;
        // }else{
        //     return i;
        // }

    }
};
