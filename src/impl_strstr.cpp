class Solution {
public:
    int strStr(string haystack, string needle) {
        int szh = haystack.size();
        int szn = needle.size();
        
        int last = szh-szn+1, ret = -1;
        for(int i = 0; i < last; ++i) {
            int j;
            for(j = 0; j < szn; j++) {
                if(needle[j] != haystack[i+j]) break;
            }
            if(j == szn) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};