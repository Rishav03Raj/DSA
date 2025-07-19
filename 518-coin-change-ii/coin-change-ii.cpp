class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
    int f(int i,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if(target%coins[i]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int nottaken = f(i-1,target,coins,dp);
        int taken = 0;
        if(coins[i]<=target){
            taken = f(i,target-coins[i],coins,dp);
        }
        return dp[i][target]= nottaken+taken;
    }
};