class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1.0;
        
        if(n > 0) {
            return impl(x, n);
        } else {
            return 1.0 / impl(x, -n);
        }
    }
    
    double impl(double x, int n) {
        int c = 31;
        while(!((n >> c) & 0x01)) c--;
        
        //cout << c << endl;
        
        double res = 1.0;
        for(; c >= 0; c--) {
            res *= res;
            if((n >> c) & 0x01) {
                res *= x;
            }
        }
        //cout << res << endl;
        
        return res;
    }
};