class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1, len2;
        len1 = word1.size();
        len2 = word2.size();
        
        vector<vector<int>> m(len2+1);
        for(int i = 0; i < len2+1; i++) {
            m[i].reserve(len1+1);
        }
        
        for(int i = 0; i < len1+1; i++) {
            m[0][i] = i;
        }
        for(int i = 0; i < len2+1; i++) {
            m[i][0] = i;
        }
        
        for(int i = 0; i < len2; i++) {
            for(int j = 0; j < len1; j++) {
                if(word1[j] == word2[i]) {
                    m[i+1][j+1] = m[i][j];
                } else {
                    m[i+1][j+1] = std::min(std::min(m[i][j+1], m[i+1][j]), m[i][j]) + 1;
                }
            }
        }
        
        return m[len2][len1];
    }
};