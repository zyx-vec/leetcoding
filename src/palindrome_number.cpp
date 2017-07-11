class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) {
            return false;
        }
        
        int res = 0, old = x;
        while(x) {
            res = (res*10) + (x % 10);
            x /= 10;
        }
        
        return (res==old);
    }
};