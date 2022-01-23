class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //先统计糖果一共多少种
        unordered_set<int> set(candyType.begin(), candyType.end());
        //然后取糖果种类数跟糖果总数的一半的较小者
        return min(set.size(),candyType.size()/2);
    }
};
