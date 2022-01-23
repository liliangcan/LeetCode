class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //题意理解错误
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     if(i+1 != nums[i]){
        //         ans.emplace_back(nums[i]);
        //         ans.emplace_back(i+1);
        //         break;
        //     }
        // }
        // return ans;
        vector<int> ans(2);
        unordered_map<int, int> m;
        int sum = 0;
        int n = nums.size();
        //首先一次遍历找出重复的元素
        for (int num : nums) {
            m[num]++;
            sum += num;
            if(m[num] == 2){
                ans[0] = num;
            }
        }
        //然后通过数学计算得出丢失的那个元素
        ans[1] = n*(n+1)/2 - sum + ans[0];
        return ans;
    }
};
