class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using nested_pair = pair<int,pair<int,int>>;
        priority_queue<
            nested_pair ,
            vector<nested_pair>,
            greater<nested_pair>
            > q;

        vector<vector<bool>> visited(n,vector<bool>(n,false));
        int mn_time = grid[0][0] ;
        q.push({mn_time,{0,0}});
        visited[0][0] = true;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        while(!q.empty()){
            auto[u,v] = q.top().second;
            int time = q.top().first;
            q.pop();
            if(u == n-1 && v== n-1){
                mn_time = time;
            }
            for(int i=0;i<4;i++){
                int nx = u+dx[i];
                int ny = v+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]){
                    q.push({max(time,grid[nx][ny]),{nx,ny}});
                    visited[nx][ny] = true;
                }
            }
        }
        return mn_time;
    }
};