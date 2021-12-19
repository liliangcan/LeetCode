class Solution {
public:
/*    void startjump(vector<int>& nums,int i){
        int tmp;
        tmp = nums[nums[i]-1];
        nums[nums[i]-1] = nums[i];
        if(nums[tmp-1] != tmp){
            startjump(nums,tmp-1);
        }
    }       */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
/*        vector<int> missnum;
        int i;
        for(i=0;i<nums.size();i++){
            if(i+1 != nums[i] && nums[nums[i]-1] != nums[i]){
                startjump(nums,i);
            }
        }
        for(i=0;i<nums.size();i++){
            if(i+1 != nums[i]){
                missnum.push_back(i+1);
            }
        }
        return missnum;             */

        int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;      //依次找到有的数，并让其加上一个n值
            nums[x] += n;
        }
        vector<int> missnum;
        for (int i=0;i<n;i++) {
            if (nums[i] <= n) {         //判断，若大于n，说明存在，反之miss
                missnum.push_back(i + 1);
            }
        }
        return missnum;
    }
};
