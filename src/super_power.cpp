class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int sz = b.size();
        a %= 1337;
        int ret = mypow(a, b[0]);
        if(sz == 1) {
            return ret;
        }
        
        for(int i = 1; i < sz; ++i) {
            ret = (pow10(ret)*mypow(a, b[i])) % 1337;
        }
        return ret;
    }
    
    int pow10(int a) {
        int c;
        a = (a*a) % 1337;   // 2
        c = (a*a) % 1337;   // 4
        c = (c*c) % 1337;   // 8
        return (a*c)%1337;  // 2+8 == 10
    }
    
    int mypow(int a, int b) {
        if(b == 0) return 1;
        
        if(b % 2) {
            return (a*(square(mypow(a, b/2)) % 1337)) % 1337;
        } else {
            return (square(mypow(a, b/2)) % 1337);
        }
    }
    
    int square(int n) {
        return n*n;
    }
};