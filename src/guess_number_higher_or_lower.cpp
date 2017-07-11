// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int g = (left+right)/2;
        int r;
        
        while((r = guess(g)) != 0) {
            if(r < 0) {
                right = g-1;
            } else {
                left = g+1;
            }
            g = left/2 + right/2;   // (left+right)/2 存在溢出的可能性！！！
            if(left&1 && right&1) g += 1;
        }
        
        return g;
    }
};