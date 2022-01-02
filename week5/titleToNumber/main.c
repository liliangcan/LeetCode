class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        long multi = 1;         //设置初始权值
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            int k = columnTitle[i] - 'A' + 1;
            number += k * multi;
            multi *= 26;        //每左移一位，权值乘上26
        }
        return number;
    }
};
