class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int total = length * (length + 1) / 2;      //计算本来应该的总和
        int curSum = 0;
        for (int i = 0; i < length; i++) {
        curSum += nums[i];                      //计算当前数组数的总和
        }
        return total - curSum;                  //减去得到丢失的数
    }
};
