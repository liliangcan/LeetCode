class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        //从左到右一次遍历
        // vector<int> ans = {-1,-1};       //设置默认值
        // int n = nums.size();
        // if(n == 0){             //若大小为空，则返回默认值
        //     return ans;
        // }
        // for(int i = 0; i < n; i++){
        //     if(ans[0] == -1 && nums[i] == target){      //找第一个与target相等的元素的下标
        //         ans[0] = i;
        //     }
        //     if(ans[0] != -1 && nums[i] == target && i == n-1){      //若相等元素持续到数组的最后一位
        //         ans[1] = i;
        //         break;
        //     }
        //     if(ans[0] == -1 && nums[i] > target){       //若没找到有相等元素则终止循环
        //         break;
        //     }else if(nums[i] > target){             //找最后一个与target相等的元素的下标
        //         ans[1] = i-1;
        //         break;
        //     }
        // }
        // return ans;

        //使用二分查找法
        vector<int> ans = {-1,-1};      //设置默认值
        int n = nums.size();
        if(n == 0){          //若大小为空，则返回默认值
            return ans;
        }
        if(n == 1){         //特殊判断一下当数组大小为1时的情况
            if(nums[0] == target){
                return {0,0};
            }else{
                return ans;
            }
        }
        int left = 0, right = n-1;
        while(left <= right){           //第一次找第一个相等元素的下标
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {      //关键判断
                right = mid - 1;
                ans[0] = mid;
            } else {
                left = mid + 1;
            }
        }
        if(ans[0] == -1){       //若没找到有相等元素则直接返回默认值(其实是数组所有值都小于target)
            return ans;
        }
        if(nums[ans[0]] == target){
            left = ans[0];
            right = n-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if (nums[mid] > target) {       //实际是找第一个大于target的元素下标
                    right = mid - 1;
                    ans[1] = mid - 1;           //然后将下标-1赋值到ans中
                } else {
                    left = mid + 1;
                }
            }
            if(ans[1] == -1){   //若相等元素持续到数组的最后一位，在上面的循环中会直接出来，需要特别赋值到ans中
                ans[1] = n-1;
                return ans;
            }
        }else{          //这也是数组中没找到相等元素返回默认值（其实是第一次循环中找的下标对应的数大于target）
            return {-1, -1};
        } 
        return ans;
    }
};
