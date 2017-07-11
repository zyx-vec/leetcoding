class Solution {
public:
    char findTheDifference(string s, string t) {
        int table1[26] = { 0 };
        int table2[26] = { 0 };
        
        int i;
        for(i = 0; i < s.size(); i++) {
            table1[s[i]-'a']++;
            table2[t[i]-'a']++;
        }
        table2[t[i]-'a']++;
        
        for(i = 0; i < 26; i++) {
            if(table1[i] != table2[i]) {
                break;
            }
        }
        
        return i+'a';
    }
};