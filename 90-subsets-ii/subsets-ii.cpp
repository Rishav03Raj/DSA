class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> st;
        vector<int> ds;
        f(nums,st,ds,0);
        return st;
    }
    void f(vector<int>&ns,vector<vector<int>> &st,vector<int>& ds,int ind){
        st.push_back(ds);
        for(int i=ind;i<ns.size();i++){
            if(i!=ind && ns[i]==ns[i-1]) continue;
            ds.push_back(ns[i]);
            f(ns,st,ds,i+1);
            ds.pop_back();
        }
    }
};