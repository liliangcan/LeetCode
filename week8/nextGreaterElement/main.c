class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        stack<int> s;       //设置临时栈
        for (int i = nums2.size()-1; i >= 0; --i) {
            int num = nums2[i];
            //一直pop，直到找到大于num的元素
            while (!s.empty() && num >= s.top()) {
                s.pop();
            }
            //若不存在则存入-1，否则存入临时栈的栈顶元素，也即右侧第一个更大元素
            hashmap[num] = s.empty() ? -1 : s.top();
            s.push(num);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            ans.push_back(hashmap[nums1[i]]);
        }
        return ans;
    }
};
