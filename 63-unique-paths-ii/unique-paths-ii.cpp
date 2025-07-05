class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return path(obstacleGrid,dp,m-1,n-1);
    }
    int path(vector<vector<int>>& v,vector<vector<int>>& dp,int i,int j){
        
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
         if(v[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        
        int up = path(v,dp,i-1,j);
        int left = path(v,dp,i,j-1);
        return dp[i][j] = up+left;
    }
};