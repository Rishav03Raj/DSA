class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> mp;
        int sm = 0, duplicate;
        for(auto row:grid){
            for(auto i:row){
                mp[i]++;
                if(mp[i]==2) duplicate=i;
                sm += i;
            }
        }
        int no = n*n;
       int  missing =  (no*(no+1)/2) - sm + duplicate;
       return  {duplicate,missing};
    }
};