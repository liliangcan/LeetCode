class Solution {
public:
    string reverseVowels(string s) {
        // auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
        //     return vowels.find(ch) != string::npos;
        // };
        string vowels = "aeiouAEIOU"s;
        auto isVowel = [vowels](char ch) {
            return vowels.find(ch) != string::npos;
        };
        // string vowels = "aeiouAEIOU";
        // bool isVowel(char ch){
        //     return vowels.find(ch) != npos;
        // }
        int n = s.size();
        int i = 0, j = n - 1;       //利用双指针，分别从头和尾开始扫描
        while (i < j) {
            while (i < n && !isVowel(s[i])) {
                ++i;
            }
            while (j > 0 && !isVowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);       //交换对应位置的元音字母
                ++i;
                --j;
            }
        }
        return s;
    }
};
