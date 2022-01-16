class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> findSame;           //定义一个map表用来存放元素
        for(int i = 0; i < nums.size(); i++){
            //当发现已经存在map表中且相距在k内的直接返回true
            if(findSame.count(nums[i]) && abs(findSame[nums[i]]-i) <= k){
                return true;
            }
            //否则加入map表中
            findSame[nums[i]] = i;
        }
        //当遍历完发现都没有，则返回false
        return false;
    }
};
