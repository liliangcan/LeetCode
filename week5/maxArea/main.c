class Solution {
public:
    int maxArea(vector<int>& height) {
//        int contain = 0;
//        for(int i = 0;i < height.size()-1;i++){
//            for(int j = 1;j < height.size();j++){
//                int temp = (j-i)*(height[i]<height[j]?height[i]:height[j]);
//                if(temp > contain){
//                    contain = temp;
//                }
//            }
//        }
//        return contain;
        int left = 0, right = height.size() - 1;           //设置起始边界，最外面
        int maxcontain = 0;
        while (left < right) {
            int currarea = min(height[left], height[right]) * (right - left);         //计算当前面积
            maxcontain = max(maxcontain, currarea);                 //取最大值为maxcontain
            if (height[left] <= height[right]) { left++; }
            else { right--;}
        }
        return maxcontain;
    }
};
