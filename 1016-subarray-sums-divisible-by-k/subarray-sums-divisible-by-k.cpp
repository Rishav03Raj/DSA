class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int c=0,prsm=0;
        for(int i:nums){
            prsm+=i;
            int mod = ((prsm % k) + k)%k ;
            if(mp.find(mod)!=mp.end()){
                c+=mp[mod];
            }
            mp[mod]++;
        }
        return c;
    }
};