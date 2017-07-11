class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26] = { 0 };
        
        for(int i = 0; i < ransomNote.size(); i++) {
            table[ransomNote[i]-'a'] += 1;
        }
        
        for(int i = 0; i < magazine.size(); i++) {
            if(table[magazine[i]-'a'] > 0) {
                table[magazine[i]-'a']--;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(table[i] > 0)
                return false;
        }
        
        return true;
    }
};