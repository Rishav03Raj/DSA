class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        int m = edges.size();
        int a = edges[0].size();
        for(auto con:edges){
            int u = con[0];
            int v=con[1],wt = con[2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==1e9 || mat[k][j]==1e9) continue;
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int ct = -1,mn = n+1;
         for(int i=0;i<n;i++){
            int cn = 0;
                for(int j=0;j<n;j++){
                    if(mat[i][j]!=1e9 && mat[i][j]<=distanceThreshold) {
                        cn++;
                    }
                }
            if(cn<=mn){
                mn = cn;
                ct = i;
            }
            }
        return ct;
    }
};