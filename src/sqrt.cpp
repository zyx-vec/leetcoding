class Solution {
public:
    int mySqrt(int x) {
        double delta = 0.01, guess = 1.0;
        while(abs(guess*guess-x) > delta) {
            guess = (guess + x/guess) / 2;
        }
        
        int n = (int)guess;
        
        return n;
    }
};