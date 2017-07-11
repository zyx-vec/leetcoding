class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        count = n&0x1;
        while(n){
            count += (n = n>>1)&0x1;
        }
        return count;
    }
};