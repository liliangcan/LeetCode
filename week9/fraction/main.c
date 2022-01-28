class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int n = cont.size();
        int c = 1, d = cont[n-1];
        //因为已经设置过初始值，则从 i = n-2 开始
        for(int i = n-2; i >= 0; i--) {
            // a[i] + c / d = (a[i] * d + c) / d
            int new_c = cont[i] * d + c;
            int new_d = d;
            // 化简最简分数
            int g = gcd(new_c, new_d);
            new_c /= g;
            new_d /= g;
            // 取倒数，赋值给新的 c / d
            c = new_d;
            d = new_c;
        }
        swap(c, d); // 最后一轮，没有取倒数这一步
        return vector<int>{c, d};
    }
};
