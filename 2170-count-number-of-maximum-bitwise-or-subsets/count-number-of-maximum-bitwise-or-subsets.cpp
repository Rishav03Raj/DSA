class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int btor = 0;
        for(int i=0;i<n;i++){
             btor = (btor|nums[i]);

        }
        // cout<<btor;
        vector<vector<int>> dp(n+1,vector<int>(btor+1,-1));
        return f(n-1,btor,0,nums,dp);
    }
    int f(int i,int b,int s,vector<int>& nums,vector<vector<int>> &dp){
        if(i<0){
            if(s==b){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int nottake = 0+f(i-1,b,s,nums,dp);
        int take = f(i-1,b,s|nums[i],nums,dp);
        return  dp[i][s]= nottake+take;
    }
};