class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        string medal[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            //此处选择负数，是为了之后的排序，从小到大排序，实质就是分数从高到低
            arr.emplace_back(make_pair(-score[i], i));
        }
        sort(arr.begin(), arr.end());
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            if (i >= 3) {
                //根据arr[i].second，将字符串放到相应的位置
                ans[arr[i].second] = to_string(i + 1);
            } else {
                ans[arr[i].second] = medal[i];
            }
        }
        return ans;
    }
};
