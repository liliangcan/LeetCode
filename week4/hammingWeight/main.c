class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n) {
            n &= n - 1;             //每与一次都会消去一个1，消去一个weight++
            weight++;
        }
        return weight;    
    }
};
