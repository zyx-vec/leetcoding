class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0]) return 0;
        
        int m, n;
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i].reserve(m);
        }
        
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[0][i] != 1) {
                ans[0][i] = 1;
            } else {
                for(int j = i; j < m; j++) {
                    ans[0][j] = 0;
                }
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] != 1) {
                ans[i][0] = 1;
            } else {
                for(int j = i; j < n; j++) {
                    ans[j][0] = 0;
                }
                break;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
            }
        }
        
        return ans[n-1][m-1];
    }
};