class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> st;
        vector<int> ds;
         f(nums,ds,st,0);
         return st;
    }
    void f(vector<int>& nums,vector<int>& ds,vector<vector<int>> &st,int ind){
        if(ind==nums.size()){
            st.push_back(ds);
            return ;
        }
        ds.push_back(nums[ind]);
        f(nums,ds,st,ind+1);
        ds.pop_back();
        f(nums,ds,st,ind+1);
    }
};