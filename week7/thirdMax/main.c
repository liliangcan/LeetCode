class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
            //若集合中已经有3个元素了，就删除最前面的一个也即最小的那一个
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        //最后判断s的大小，若是3就直接返回第一个元素，若小于3则返回最后一个元素
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
