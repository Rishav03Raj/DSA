class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0,j=1,it=0;
        while(it<n){
            if(nums[it]>0){
                ans[i]=nums[it];
                i+=2;
            }
            else if(nums[it]<0){
                ans[j]=nums[it];
                j+=2;
            }
            it++;
        }
        return ans;
    }
};