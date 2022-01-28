class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while(left <= right){       //二分查找
            mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        //没有找到目标值的情况
        if(nums[mid] != target){
            return -1;
        }
        return mid;
    }
};
