class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m,vector<int>(n,-1));
       return path(grid,v,m-1,n-1);
    }
int path(vector<vector<int>>& grid,vector<vector<int>>& v,int i,int j){
    if(i<0 || j<0) return 1000000;
    if(v[i][j]!=-1) return v[i][j];
    if(i==0 && j==0) return grid[i][j];
    int up = grid[i][j] + path(grid,v,i-1,j);
    int left = grid[i][j] + path(grid,v,i,j-1);
    return v[i][j] = min(up,left);
}

};