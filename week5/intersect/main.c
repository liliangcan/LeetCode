class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);                 //保证输入参数的顺序
        }
        unordered_map <int, int> m;
        for (int num : nums1) {                             //用map来记录较短数组中每个数字出现的次数
            ++m[num];
        }
        vector<int> intersection;
        for (int num : nums2) {
            if (m.count(num)) {                     //若在map表中，就加入intersection，map中的对应值减一
                intersection.push_back(num);
                --m[num];
                if (m[num] == 0) {              //若已经减到一了，就从map表中删去
                    m.erase(num);
                }
            }
        }
        return intersection;
    }
};
