class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w) {
            w--;
        }
        int l = area/w;
        return {l, w};
    }
};
