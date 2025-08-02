class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       const int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        // for(auto row:adj){
        //     for(auto col:row){
        //         cout<<col<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> visited(n, false);
        queue<int> q;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                count++;
                visited[i] = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto neigh : adj[node]) {
                        if (!visited[neigh]) {
                            q.push(neigh);
                            visited[neigh]=true;
                        }
                    }
                }
            }
        }
        return count;
    }
};