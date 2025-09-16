class Solution {
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& cn) {
        int n = cn.size();
        // int m = cn[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && cn[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            cnt++;
            dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};