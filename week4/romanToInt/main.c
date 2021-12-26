class Solution {
private:
    unordered_map<char, int> symbolValues = {       //构建罗马数字map表
        {'I', 1},{'V', 5},{'X', 10},{'L', 50},
        {'C', 100},{'D', 500},{'M', 1000},
    };

public:
    int romanToInt(string s) {
        int value1,value2,result = 0;
        int n = s.length();
        value1 = symbolValues[s[0]];            //value1首先放入第一个数字
        for (int i = 1; i <= n; ++i) {
            value2 = symbolValues[s[i]];        //value2放入下一个数字
            if (i < n  && value1 < value2) {        //判断，若前面的小于后面的，说明需要减去value1的值
                result -= value1;
            } else {                            //否则就是正常情况，直接加上
                result += value1;
            }
            value1 = value2;
        }
        return result;
    }

};
