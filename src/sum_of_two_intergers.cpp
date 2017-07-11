class Solution {
public:
    int getSum(int a, int b) {
        int m = 1, c = 0;
        int sum = 0;
        for(int i = 0; i < 32; i++) {
            int t = ((m&a? 1: 0)<<2) | ((m&b? 1: 0)<<1) | c;
            switch(t) {
                case 0: c = 0; break;
                case 1: 
                case 2:
                case 4: sum |= m; c = 0; break;
                case 3:
                case 5:
                case 6: c = 1; break;
                default: sum |= m; c = 1; break;
            }
            m <<= 1;
        }
        //cout << sum << endl;
        return sum;
    }
};