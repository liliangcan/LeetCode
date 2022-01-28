class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        //先排序
        sort(intervals.begin(), intervals.end());
        if(intervals.size() <= 1){
            return intervals;
        }
        for(int i = 0,j = i+1; j < intervals.size(); i = j){
            while(j < intervals.size()){
                //若前一个包含后一个，则跳过下一个
                if(intervals[i][1] >= intervals[j][1]){
                    // intervals.erase(intervals.begin()+i+1);n--;  //报错运行时间太长？
                    j++;
                }else if(intervals[i][1] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    //若前一个跟后一个相交，则取最大的范围
                    intervals[i][1] = intervals[j][1];
                    // intervals.erase(intervals.begin()+i+1);n--;
                    j++;
                }else{
                    break;
                }
            }
            //将一次循环的最后结果存入ans
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
