class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size();){
            //当前位置没花且下一个位置也没花或者已经到花坛边缘，此时可以种植，count++
            if(flowerbed[i] == 0 && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
                count++;
                i += 2;
            }else if(flowerbed[i] == 0 && flowerbed[i+1] == 1){
                //当前位置没花，但是下一个位置有花，则直接跨三步
                i += 3;
            }else if(flowerbed[i] ==1){
                //当前位置有花，直接跨两步看下一个可能位置的情况
                i += 2;
            }
            //若某一步发现可种植的位置已经达到要求，直接返回true就OK
            if(count >= n){
                return true;
            }
        }
        return false;
    }
};
