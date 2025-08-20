class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int j=0;
        for(auto i:s){
            nums[j]=i;
            j++;
        }
        return j;
    }
};