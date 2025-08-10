class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==0) {
            visited[0][0]=1; 
            q.push({{0,0},1});
        }
        int fx,fy;
        
        while(!q.empty()){
            auto [u,d]=q.front();
            auto [x,y]= u;
          fx=x,fy=y;
            q.pop();
            if(fx==n-1 && fy == m-1) return d;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = x+i;
                    int ny = y+j;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==0){
                        visited[nx][ny]=1;
                        q.push({{nx,ny},d+1});
                    }
                }
            }
        }
    //     if(fx!=n-1 || fy!=m-1) return -1;
    //     return mx;
    return -1;
    }
};