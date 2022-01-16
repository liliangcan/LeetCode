class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){     //若非正数则直接返回false
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (int factor : factors) {
            //若还存在这些因子，就不断除去
            while (n % factor == 0) {
                n /= factor;
            }
        }
        //最后判断商是否为1
        return n == 1;
    }
};
