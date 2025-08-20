class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s(nums.begin(),nums.end());
        int n = nums.size(),i=0,j=1;
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};