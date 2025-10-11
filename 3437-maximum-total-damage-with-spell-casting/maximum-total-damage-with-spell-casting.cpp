class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<long long,int> mp;
        vector<long long> v;
        for(long long i:power) mp[i]++;
        for(auto &[i,_]:mp) v.push_back(i);
        sort(v.begin(),v.end());
        int s = v.size();
        vector<long long> dp(s);
        dp[0] = v[0]*mp[v[0]];
        for(int i=1;i<s;i++){
            long long cur = v[i]*mp[v[i]];
            int j = i-1;
            while(j>=0){
                if(v[j]<v[i]-2) break;
                j--;
            }
            if(j>=0){
                cur += dp[j];
            }
            dp[i] = max(cur,dp[i-1]);
        }
    return dp[s-1];
    }
};