class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sm = INT_MIN,
        cs  = 0;
        for(int i=0;i<n;i++){
            cs+=nums[i];
             sm = max(sm,cs);
            if(cs<0){
                cs = 0;
            }
        }
        return sm;
    }
};