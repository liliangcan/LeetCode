class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR = m,minC = n;      //首先设置minR、minC为原矩阵大小       
        //找到操作的行最小值，列最小值，然后两者相乘，可以得到被加一的最多的那一部分
        //也就是需要返回的范围
        for(int i = 0; i < ops.size(); i++){
            minR = min(ops[i][0],minR);
            minC = min(ops[i][1],minC);
        }
        return minR*minC;        //如果不对矩阵进行操作，就返回原矩阵的范围
    }
};
