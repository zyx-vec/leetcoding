class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
		m = grid.size();
		n = grid[0].size();
		
		vector<vector<int>> square(m);
		for(int i = 0; i < m; i++) {
			square[i].reserve(n);
			square[i].resize(n);
		}
		
		square[0][0] = grid[0][0];
		for(int i = 1; i < n; i++) {
			square[0][i] = grid[0][i]+square[0][i-1];
		}
		for(int i = 1; i < m; i++) {
			square[i][0] = grid[i][0]+square[i-1][0];
		}
		
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				square[i][j] = min(square[i-1][j]+grid[i][j], square[i][j-1]+grid[i][j]);
			}
		}
		
		return square[m-1][n-1];
    }
};