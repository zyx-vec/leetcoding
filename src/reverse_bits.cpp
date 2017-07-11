class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int value = 0;
        for(int i = 0, j = 31; i<32 ; i++, j--){
            value ^= ((n>>i)&0x1)<<j;
        }
        return value;
    }
};