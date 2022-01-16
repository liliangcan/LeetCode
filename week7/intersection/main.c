class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> temp{ nums1.begin(), nums1.end() };
        for (auto& iter : nums2) {
            //set.find(key)返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器
            if (temp.find(iter) != temp.end()) {
                ans.emplace_back(iter);
                // ans.push_back(iter);
                temp.erase(iter);
            }
        }
        return ans;
    }
};
