class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(0,0,n,target,nums);
    }
    int f(int i,int sm,int n,int target,vector<int>& nums){
        if(i==n){
            if(sm==target){
                return 1;
            }
            else return 0;
        }
        int plus = f(i+1,sm+nums[i],n,target,nums);
        int minus = f(i+1,sm-nums[i],n,target,nums);
        return plus+minus;
    }
};