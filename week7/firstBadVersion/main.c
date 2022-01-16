// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        //会溢出报错
        // int mid = (left+right)/2;
        int mid = left + (right - left) / 2;
        while(left < right){
            if(isBadVersion(mid)){
                right = mid-1;
                // mid = (left+right)/2;
                mid = left + (right - left) / 2;
            }
            else{
                left = mid+1;
                mid = left + (right - left) / 2;
            }
        }
        if(isBadVersion(left)){
            return left;
        }else{
            return ++left;
        }
    }
};
