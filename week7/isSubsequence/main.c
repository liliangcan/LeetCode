class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;
        int lens = s.length();
        int lent = t.length();
        //使用双指针，一个用来遍历s，一个用来遍历t
        //若有相等位置就都++，否则t的指针p2++
        while(p1 < lens && p2 < lent){
            if(s[p1] == t[p2]){
                p1++;
                p2++;
            }else{
                p2++;
            }
        }
        //最后判断，若p1已经与s的长度相等，说明确定是t的子串，返回true
        return p1 == lens;
    }
};
