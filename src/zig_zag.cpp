class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        if (numRows >= s.size()) {
            return s;
        }
        vector<string> vv(numRows);
        int row = -1;
        int step = 1;
        for (int i = 0; i < s.size(); i++) {
            row += step;
            vv[row].push_back(s[i]);
            if (row == numRows-1) {
                step = -1;
            }
            if (row == 0) {
                step = 1;
            }
        }
        
        string res;
        for(int i = 0; i < numRows; i++) {
            res += vv[i];
        }
        return res;
    }
};