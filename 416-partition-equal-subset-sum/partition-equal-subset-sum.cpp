class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(),0);

        if(s%2!=0) return false;
        int target=s/2;
        vector<bool> prv(target+1,false);
        prv[0]=true;
        if(nums[0]<=target){
            prv[nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int j=1;j<=target;j++){
                bool nottaken = prv[j];
                bool taken  = false;
                if(nums[i]<=j){
                    taken = prv[j-nums[i]];
                }
                curr[j]= taken|nottaken;
            }
            prv = curr;
        }
        return prv[target];

    }
};