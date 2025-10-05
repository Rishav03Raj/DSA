class Solution {
    static constexpr int dx[]={0,-1,0,1};
    static constexpr int dy[]={-1,0,1,0};
private:
    void dfs(int u,int v,vector<vector<int>>& heights,vector<vector<int>> &p){
        int n = heights.size();
        int m = heights[0].size();
        p[u][v]=1;
        for(int i=0;i<4;i++){
            int nx = u+dx[i];
            int ny = v+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[u][v]){
                 if(!p[nx][ny]){
                     dfs(nx,ny,heights,p);          
                            }
        }
    }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));
        

        for(int i=0;i<n;i++){
              dfs(i,0,heights,p); 
              dfs(i,m-1,heights,a); 
        }

        for(int i=0;i<m;i++){
              dfs(0,i,heights,p); 
              dfs(n-1,i,heights,a); 
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};