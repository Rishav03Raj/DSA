class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int c = 0,prsm=0;
        for(int i=0;i<n;i++){
            prsm+=nums[i];
            if(mp.find(prsm-k)!=mp.end()){
                c+=mp[prsm-k];
            }
            mp[prsm]++;
        }
        return c;
    }
};