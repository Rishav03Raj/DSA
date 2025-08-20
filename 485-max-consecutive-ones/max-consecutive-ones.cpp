class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx=0,cn=0;
        for(int i:nums){
            if(i==0){
                mx = max(cn,mx);
                cn=0;
            }
            else{
                cn++;
            }
        }
        return max(cn,mx);
    }
};