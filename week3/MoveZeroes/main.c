class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int th = 0;         //设置即将被非零元素替代的位置
        for(int i=0;i<nums.size();i++){
            if(nums[i]){            //当元素非零时，将当前元素赋给num[th]，当前位置清零
                nums[th] = nums[i];
                if(i!=th){nums[i] = 0;}
                th++;
            }
        }
    }
};
