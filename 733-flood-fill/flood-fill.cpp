class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int org = image[sr][sc];
        vector<vector<int>> copy(image);
        if(copy[sr][sc]==color) return copy;
        int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        copy[sr][sc]=color;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 ||ny<0 || nx>=n || ny>=m || copy[nx][ny]!=org)
                continue;
                copy[nx][ny]=color;
                q.push({nx,ny});
            }
        }
        return copy;
    }
};