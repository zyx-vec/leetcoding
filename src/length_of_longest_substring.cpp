class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l, r, ret = 0, len;
        l = -1;
		r = 0;
        len = s.size();
        
        if(len < 2) return len;
        
        map<char, int> hTable; 
     
        for(; ;) {
			
            while(r < len && hTable[s[r]-'a']==0) {
				hTable[s[r]-'a'] = 1;
				r++;
			}
			
			if(r-l-1 > ret) ret = r-l-1;
			
			if(r >= len-1) break;

            while(s[++l] != s[r]) {
				hTable[s[l]-'a'] = 0;
			}
			hTable[s[l]-'a'] = 0;

            if(r >= len-1) break;
        }
        return ret;
    }
};