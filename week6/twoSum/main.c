class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //使用两个下标分别从左边和右边开始
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                //若小于目标数，则左边下标右移
                left++;
            } else {
                //若大于目标数，则右边下标左移
                right--;
            }
        }
        return {-1, -1};
    }
};
