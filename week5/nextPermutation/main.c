class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {      //从右往左，找到第一个不符合降序的数
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {      //从右往左，找到比刚刚的数大的第一个数
                j--;
            }
            swap(nums[i], nums[j]);                     //然后进行交换
        }
        reverse(nums.begin() + i + 1, nums.end());      //最后将i之后的数变成升序
    }
};
