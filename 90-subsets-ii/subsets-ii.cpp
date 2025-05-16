class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> ds;
        f(nums,st,ds,0);
        vector<vector<int>> stv(st.begin(),st.end());
        return stv;
    }

    void f(vector<int>& nums,set<vector<int>> &st,vector<int>& ds,int ind){
        if(ind==nums.size()){
            st.insert(ds);
            return ;
        }
        ds.push_back(nums[ind]);
        f(nums,st,ds,ind+1);
        ds.pop_back();
        f(nums,st,ds,ind+1);
    }
};