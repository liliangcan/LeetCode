class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto needed = map.find(target - nums[i]);   //定义变量用来存放查找到的值
            if(needed != map.end()) {
                return {needed->second, i};     //若已存在哈希表里，就返回结果
            }
            map[nums[i]] = i;       //若不存在，就把当前值存入哈希表
        }
        return {};
    }
};
