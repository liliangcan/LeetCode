/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //二分查找
        int left = 1,right = n;
        int mid = left + (right - left)/2;
        while(left < right){
            if(guess(mid) > 0){
                left = mid + 1;
            }else if(guess(mid) < 0){
                right = mid - 1;
            }else{
                return mid;
            }
            mid = left + (right - left)/2;
        }
        return left;
    }
};
