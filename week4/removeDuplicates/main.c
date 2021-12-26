class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()){                       //若数组为空则返回0
            return 0;
        }else if(nums.size() == 1){                 //若只有一个数返回1
            return 1;
        }
        int i = 0,j = 1;
        while(j+1 < nums.size()){                   //设置两个下标i、j，分别指向需要比较的两个数
            if(nums[i] == nums[j]){
                nums[i+1] = nums[j+1];          //若两数相等，则进行覆盖，j++
                j++;   
            }else{
                i++;                        //若不等，则直接i++
            }
        }
        if(nums[i] != nums[i+1]){           //最后一种特殊情况判断
            return i+2;                    //若这两个数不相等，说明最后被覆盖的数需要算进去
        }else{
            return i+1;                     //否则只返回到目前下标i的数即可
        }
    }
};
