class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev= nums[0] ;
        int curr = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;
            int notpick = 0+prev;
            curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> v1,v2;
        for(int i=0;i<n;i++){
            if(i!=0) v1.push_back(nums[i]);
            if(i!=n-1) v2.push_back(nums[i]);
        }
        return max(rob1(v1),rob1(v2));

    }
};