class Solution {
public:
    string toHex(int num) {
        string table = "0123456789abcdef";
        
        string ret;
        int value;
        for(int i = 0; i < 8; i++) {
            value = num & 0xf;
            ret.push_back(table[value]);
            
            num >>= 4;
            
            if(num == 0) {
                break;
            }
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};