class Solution {
public:
    void path(vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int lf = matrix[i][j] + ((j-1 >= 0) ? dp[i-1][j-1] : (int)1e9);
                int dw = matrix[i][j] + dp[i-1][j];
                int rt = matrix[i][j] + ((j+1 < n) ? dp[i-1][j+1] : (int)1e9);

                dp[i][j] = min(lf, min(dw, rt));
    }
}


    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        path(matrix,dp);
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            int ans = dp[n-1][i] ;
            mn = min(ans,mn);
        }
        return mn;
    }
};