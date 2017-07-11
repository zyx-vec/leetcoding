class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num & num-1) {   // power of 2
            return false;
        }
        
        for(int i = 0; i < 16; i++) {
            if(num == 1<<(i*2)) {
                return true;
            }
        }
        
        return false;
    }
};