class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sTot;         //定义两个映射的map表
        unordered_map<char, char> tTos;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            //若下一个是已经存在map中的映射且出现矛盾，返回false
            if ((sTot.count(x) && sTot[x] != y) || (tTos.count(y) && tTos[y] != x)) {
                return false;
            }
            //否则加入映射表中
            sTot[x] = y;
            tTos[y] = x;
        }
        return true;        //若一直到最后都没有出现矛盾，则说明同构，返回true
    }
};
