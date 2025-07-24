class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,s1,s2,dp);
    }
    int f(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]= 0+f(i-1,j-1,s1,s2,dp);
        else{
            return dp[i][j] = 1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
        }
    }
};