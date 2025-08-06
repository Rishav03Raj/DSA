class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> copy(mat);
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(copy[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=1;
               }
            }
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int k = q.front().second;
            copy[x][y]=k;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || visited[nx][ny]){
                    continue;
                }
                visited[nx][ny]=true;
                q.push({{nx,ny},k+1});
            }
            
        }
        return copy;

    }
};