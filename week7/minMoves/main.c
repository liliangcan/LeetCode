class Solution {
public:
    int minMoves(vector<int>& nums) {
        //利用迭代器找到nums中的最小元素，以即基数
        int minNum = *min_element(nums.begin(),nums.end());
        int res = 0;
        for (int num : nums) {
            //求出每个数跟基数的差值，再累加上，最后就是需要操作的最少次数
            res += num - minNum;
        }
        return res;
    }
};
