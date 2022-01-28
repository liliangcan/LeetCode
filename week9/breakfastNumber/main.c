class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end());
        // 超时
        // int ans = 0;
        // for(int i = 0;i < staple.size() && staple[i] < x; i++){
        //     for(int j = 0;j < drinks.size() && drinks[j]+staple[i] <= x; j++){
        //         if(drinks[j]+staple[i] <= x){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        int i = 0, j = drinks.size() - 1;
        long ans = 0;
        while(i < staple.size() && j >= 0) {
            int sum = staple[i] + drinks[j];
            if (sum <= x) {
                i++;
                //因为j是从后往前，前面的肯定比后面的小，所以可以直接加上
                ans += j+1;
                ans %= 1000000007;
            } else {
                j--;
            }
        }
        return ans % 1000000007;

    }
};
