class Solution {
public:
    bool isPerfectSquare(int num) {
        
        double delta = 0.01, guess = 1.0;
        while(abs(guess*guess-num) > delta) {
            guess = (guess + num/guess) / 2;
        }
        
        int n = (int)guess;
        
        return n*n == num || (n+1)*(n+1) == num;
    }
};