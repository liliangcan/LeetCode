class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        //num1、num2没结束后者进位值不为0都继续循环
        while (i >= 0 || j >= 0 || add != 0) {
            //减去‘0’，是为了利用ASC码，把字符变成int型整数
            int x = i>=0 ? num1[i]-'0' : 0;
            int y = j>=0 ? num2[j]-'0' : 0;
            int result = x + y + add;
            //加上‘0’，是为了利用ASC码，把int型整数变成字符
            ans.push_back('0' + result % 10);
            add = result / 10;      //暂存进位
            i--;
            j--;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
