class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int length = nums.size();
        //设置循环跳出条件，因为这之后的数是被“删除”的数，不需要继续考虑
        while(i<length){
            if(nums[i] != val){
                i++;
                //发现当前位置不相等后直接进入下一轮循环
                continue;
            }
            swap(nums[i],nums[length-1]);
            length--;
        }
        return length;
    }
};
