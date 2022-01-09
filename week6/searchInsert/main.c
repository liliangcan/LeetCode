class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = (left + right)/2;
        //使用二分查找法，循环结束条件是left=right
        while(left < right){
            if(target < nums[mid]){
                right = mid-1;
            }else if(target > nums[mid]){
                left = mid+1;
            }else{
                return mid;
            }
            mid = (left + right)/2;
        }
        //这时left=right=mid
        //比较当前数与target的大小来判断返回值
        return target>nums[left]?(left+1):left;
    }
};
