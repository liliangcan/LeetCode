class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mySet;
        for (auto w: wordDict) {
            //将字典中的单词都先加入set中
            mySet.insert(w);
        }
        //定义一个向量，用来标记字符串中是否存在合理的单词位置
        vector<bool> ans(s.size() + 1);
        ans[0] = true;
        for (int i = 1; i <= s.size(); i++) {       //右边界下标
            for (int j = 0; j < i; j++) {
                //find函数返回指向该元素的迭代器
                if (ans[j] && mySet.find(s.substr(j, i - j)) != mySet.end()) {
                    //找到一个子串，（末尾）标记为true
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[s.size()];
    }
};
