class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > square(m);
		
		for(int i = 0; i < m; i++) {
			square[i].reserve(n);
			square[i].resize(n);
		}
		
		for(int i = 0; i < n; i++) {
			square[0][i] = 1;
		}
		for(int i = 1; i < m; i++) {
			square[i][0] = 1;
		}
		
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				square[i][j] = square[i-1][j] + square[i][j-1];
			}
		}
		
		return square[m-1][n-1];
    }
};