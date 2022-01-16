class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //若ransomNote比magazine长一定不能由magazine构成，直接返回false
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        //ransomNote 和 magazine 由小写英文字母组成，只需考虑小写字母
        vector<int> temp(26);
        for (auto& c : magazine) {
            temp[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            temp[c - 'a']--;
            if (temp[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
