class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int,int> myMap;
        int row = source.size();
        int col = source[0].size();
        //首先利用map记录source里面的颜色
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                myMap[source[i][j]]++;
            }
        }
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                //若已经出现过就--，否则count++
                if(myMap.find(target[i][j]) != myMap.end() && myMap[target[i][j]] != 0){
                    myMap[target[i][j]]--;
                }else{
                    count++;
                }
            }
        }
        return count;
    }
};
