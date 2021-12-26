class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()){
            return 0;
        }
        int i,j;
        int nlength = needle.size();
        int hlength = haystack.size();
        int diff = hlength - nlength;
        for(i = 0; i <= diff; i++){
            bool flag = 1;
            for(j = 0;j < nlength;j++){
                if(haystack[i+j] != needle[j]){         //若出现不相等，则flag=0；并跳出这一层循环
                    flag = 0;
                    break;
                }
            }
            if(flag){
                return i;          //当flag=1，说明找到匹配的字符串，返回下标i      
            }
        }
        return -1;
    }
};
