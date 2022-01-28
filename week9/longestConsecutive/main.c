class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //无法处理负数
        // unordered_map<int,int> myMap;
        // for(int i = 0; i < nums.size(); i++){
        //     myMap[nums[i]]++;
        // }
        // int maxLength = 0, tempLength = 0;
        // for(int i = 0; i < myMap.size(); i++){
        //     if(myMap[i] > 0){
        //         tempLength++;
        //     }else{
        //         maxLength = max(maxLength,tempLength);
        //         tempLength = 0;
        //     }
        // }
        // maxLength = max(maxLength,tempLength);
        // return maxLength;

        //参考答案
        // unordered_set<int> num_set;
        // for (const int& num : nums) {
        //     num_set.insert(num);
        // }
        // int maxLength = 0;
        // for (const int& num : num_set) {
        //     if (!num_set.count(num - 1)) {
        //         int currentNum = num;
        //         int tempLength = 1;
        //         while (num_set.count(currentNum + 1)) {
        //             currentNum += 1;
        //             tempLength += 1;
        //         }
        //         maxLength = max(maxLength, tempLength);
        //     }
        // }
        // return maxLength;

        //比答案更快
        sort(nums.begin(),nums.end());  //直接先对数组进行排序
        if(nums.size() == 0){       //若大小为0，则返回0
            return 0;
        }
        int maxLength = 0, tempLength = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){       //若出现相等的元素则跳过
                continue;
            }
            if(nums[i] - nums[i-1] == 1){       //若出现连续的元素，则tempLength++
                tempLength++;
            }else{          //否则tempLength回归1
                maxLength = max(maxLength, tempLength);
                tempLength = 1;
            }
        }
        maxLength = max(maxLength, tempLength);
        return maxLength;
    }
};
