class Solution {
public:
    int expectNumber(vector<int>& scores) {
        //还有点迷茫的题意
        sort(scores.begin(), scores.end());
        return unique(scores.begin(), scores.end()) - scores.begin();
    }
};
