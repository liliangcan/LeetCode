class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        //得到水缸需要的最多的水量，也是任何情况下需要的最多的蓄水次数
        int maxk = *max_element(vat.begin(), vat.end());
        if (!maxk) {
            return 0;
        }
        int ans = INT_MAX;
        //k代表蓄水次数
        for (int k = 1; k <= maxk; ++k) {
            int cur = k;
            for (int i = 0; i < n; ++i) {
                //在蓄水次数固定为k时， 水桶容量最小应该为least
                int least = vat[i] / k + (vat[i] % k != 0);
                //least减去水桶原本容量就是需要升级的次数
                cur += max(least - bucket[i], 0);
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
