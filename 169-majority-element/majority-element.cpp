class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(),candidate,cn=0;
        // unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(cn==0){
                candidate = nums[i];
            }
            if(nums[i]==candidate){
                cn++;
            }
            else{
                cn--;
            }
            
        }
        return candidate;
    }
};