class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> memory;              //定义一个memory哈希表
        int majority = 0, count = 0;
        for (int num: nums) {
            ++memory[num];
            if (memory[num] > nums.size()/2) {          //当出现次数大于n/2
                majority = num;
                count = memory[num];
            }
        }
        return majority;
    }
};
