class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //首先对孩子胃口数组和饼干数组进行从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookies = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
            //从小到大，直到找到第一个能满足孩子胃口的饼干
            while (j < numOfCookies && g[i] > s[j]) {
                j++;
            }
            //若该饼干存在，就count++
            if (j < numOfCookies) {
                count++;
            }
        }
        return count;
    }
};
