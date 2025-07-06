class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        vector<vector<int>> dp;
        for (int i = 0; i < m; ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }

        return path(triangle,dp,0,0);
    }
    int path(vector<vector<int>>& v,vector<vector<int>>& dp,int i,int j){
        if(i==v.size()-1) return v[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = v[i][j]+ path(v,dp,i+1,j);
        int diag = v[i][j]+ path(v,dp,i+1,j+1);
        return dp[i][j]= min(down,diag);
    }
};