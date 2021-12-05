class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            if(pre<=0){         //若之前元素和非正数，则丢弃，选用当前值
                pre = x;
            }
            else{
                pre = pre+x;    //否则加上当前值成为新的pre
            }
            maxAns = max(maxAns, pre);  //在已知最大和和pre中选择最大值为maxAns
        }
        return maxAns;
    }
};
