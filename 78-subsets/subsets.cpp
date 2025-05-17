class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int l = 1<<n;
         vector<vector<int>> st;
        for(int mask=0;mask<l;mask++){
            vector<int> ds;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    ds.push_back(nums[i]);
                }
            }
            st.push_back(ds);
        }
        return st;
    }
};