class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN , curr = 0;
        int mn = INT_MAX , cmr = 0;
        int sm=0;
        for(int i=0;i<n;i++){
            curr = max(nums[i],curr+nums[i]);
            mx  = max(mx, curr);
            cmr = min(nums[i],cmr+nums[i]);
            mn = min(mn,cmr);
            sm+=nums[i];
        }
        cout<<sm<<" "<<mx<<" "<<mn;
        if(sm==mn) return mx;
         return max(mx, sm-mn);
    }
};