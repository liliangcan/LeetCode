class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string rowIdx = "12210111011122000010020202";
        char idx;
        bool isValid;
        for (auto & word : words) {
            isValid = true;
            //记录第一个字母的所在行索引
            idx = rowIdx[tolower(word[0]) - 'a'];
            for (int i = 1; i < word.size(); i++) {
                //若之后的字母存在与第一个字母行索引不一样时，直接break
                if(rowIdx[tolower(word[i]) - 'a'] != idx) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};
