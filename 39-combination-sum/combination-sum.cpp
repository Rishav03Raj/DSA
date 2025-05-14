class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ls;
        vector<int> dm;
        cs(candidates,dm,ls,target,0);
        return ls;
    }
     void cs(vector<int>& cd,vector<int>& ds,vector<vector<int>>&st, int target,int i) {
        int n = cd.size();
        if(i==n){
            if(target==0){
                st.push_back(ds);
            }
            return;
        }
        if(cd[i]<=target){
            ds.push_back(cd[i]);
            cs(cd,ds,st,target-cd[i],i);
            ds.pop_back();
        }
        cs(cd,ds,st,target,i+1);
    }

};