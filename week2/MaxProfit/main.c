class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre = 0, maxPro =0;
        int diff;
        for(int i=1;i<prices.size();i++){
            diff=prices[i]-prices[i-1];             //保存当天与前一天的差值
            if(pre<=0){
                pre = diff;
            }else{
                pre += diff;
            }
            maxPro = max(maxPro,pre);
        }
        return maxPro;
    }    
};
