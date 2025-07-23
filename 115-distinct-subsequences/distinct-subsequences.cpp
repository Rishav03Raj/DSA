class Solution {
private:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int result = 0;
        if (s[i] == t[j]) {
           int l= f(i - 1, j - 1, s, t,dp) ;
           int z =  f(i-1 , j, s, t,dp);
           result = l+z;
        } else {
            result =  f(i - 1, j, s, t,dp);
        }
         dp[i][j]=  result;
         return result;
    }

public:
   const int prime = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<int> prv(m+1,0);
        prv[0]=1;

        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        // for(int j=1;j<=m;j++){
        //     dp[0][j]=0;
        // }
        for(int i=1;i<=n;i++){
            for(int j=m;j>0;j--){
                if (s[i-1] == t[j-1]) {
                    prv[j] = (prv[j-1]+ prv[j])%prime ;
                    } else {
                         prv[j]=  prv[j]; // we can ignore else as it is same 
                    }
            }
        }
        return (int)prv[m] ;
    }
};