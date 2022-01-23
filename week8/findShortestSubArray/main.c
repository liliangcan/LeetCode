class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> max;
        int count;
        //首先利用哈希表找到度最大的那个数（那些数）
        for(auto n : nums){
            map[n]++;
            if(count < map[n]){
                max.clear();
                max.push_back(n);
                count = map[n];
            }else if(count == map[n]){
                max.push_back(n);
            }
        }
        //然后利用双指针找到最短子数组的长度
        int ans = INT_MAX;
        for(int i = 0; i< max.size(); i++){
            int left = 0, right = nums.size()-1;
            while(nums[left] != max[i]){
                left++;
            }
            while(nums[right] != max[i]){
                right--;
            }
            ans = min(ans, right - left + 1);
        }
        return ans;
    }
};
