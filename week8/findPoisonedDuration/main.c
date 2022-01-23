class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;        //总中毒持续时间
        int expired = 0;    //每次中毒应该持续到的时刻
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (timeSeries[i] >= expired) {
                //如果当前时间大于上次中毒持续到的时刻，就直接加上一个duration
                ans += duration;
            } else {
                //否则就加上两次中毒的时间差
                ans += timeSeries[i] - timeSeries[i-1];
            }
            //最后更新这次中毒将会持续到的时刻
            expired = timeSeries[i] + duration;
        }
        return ans;
    }
};
