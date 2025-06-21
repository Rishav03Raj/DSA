class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        return dp(n,v);

        
        
    }
    int dp(int n,vector<int>& d){
        if(n<=1) return 1;
        if(d[n]!=-1) return d[n];
        return d[n]=dp(n-1,d)+dp(n-2,d);
    }
   
};