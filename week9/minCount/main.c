class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for(auto c : coins){
            // ans += c/2 + c -(c/2)*2;
            ans += c/2 + c%2;
        }
        return ans;
    }
};
