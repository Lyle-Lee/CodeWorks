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
        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int tag = guess(mid);
            if (tag == 0) {
                ans = mid;
                break;
            } else if (tag > 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
