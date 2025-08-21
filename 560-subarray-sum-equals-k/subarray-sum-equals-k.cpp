class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cn = 0 , cummulSum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            cummulSum+=nums[i];
            if(mp.find(cummulSum-k)!=mp.end()){
                cn+=mp[cummulSum-k];
            }
                mp[cummulSum]++;
        }
       return cn;
    }
};