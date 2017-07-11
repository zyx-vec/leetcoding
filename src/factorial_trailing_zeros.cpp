class Solution {
public:
    int trailingZeroes(int n) {
        int rs = 0;
        while (n != 0) {
            rs += (n / 5);
            n /= 5;
        }
        return rs;
    }
};