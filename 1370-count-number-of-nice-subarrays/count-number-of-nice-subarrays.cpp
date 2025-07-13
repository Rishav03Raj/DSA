class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int cn=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) cn++;
            if(mp.find(cn-k)!=mp.end()){
                ans+=mp[cn-k];
                
            }
            mp[cn]++;
        }
       
        return ans;
    }
};