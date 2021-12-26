class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> tmp;                     //建立哈希表
        for (int x: nums) {
            if (tmp.find(x) != tmp.end()) {         //若在此时表中已找到，说明有重复元素
                return true;
            }
            tmp.insert(x);              //没有则继续插入哈希表
        }
        return false;                   //遍历完都没有，说明无重复元素
    }
};
