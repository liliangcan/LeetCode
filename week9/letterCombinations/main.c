class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        //使用哈希表存放电话中的数字和字母对应情况
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        //定义一个存放结果中每个字符串的变量
        string combination;
        //开始进入回溯函数
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char,
                    string>& phoneMap, const string& digits, int index,
                    string& combination) {
        //如果索引值已经等于digits.length，则将字符串conbination加入结果中
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            //记录索引值对应的数字
            char digit = digits[index];
            //根据数字，取出对应的字符串
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                //不断使用字符串的每一个字母，将其加入
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                //在上一次调用结束后，需要将最后一个字符弹出，也就是回溯
                combination.pop_back();
            }
        }
    }
};
