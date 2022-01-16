class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        //重新设置一个存放从当前元素到前面所有元素之和的数组
        //为了包含i，j易于操作，让新数组第一个位置为0
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
