class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(),mx=0,ans = -1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>mx) {
                mx = mp[nums[i]]; ans = nums[i];
                }
            // mx = max(mx,mp[nums[i]]);
        }
        return ans;
    }
};