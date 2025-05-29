class Solution {
public:

    void dfs(int curr,int parent,unordered_map<int,vector<int>> &adj,vector<int> &mark,int &zeroMarkedCount,int &oneMarkedCount){
        if(mark[curr]==0){
            zeroMarkedCount++;
        }
        else{
            oneMarkedCount++;
        }
    for(auto &ngbr:adj[curr]){
        if(parent!=ngbr){
            mark[ngbr]=1-mark[curr];
            dfs(ngbr,curr,adj,mark,zeroMarkedCount,oneMarkedCount);
        }
    }
    }

    unordered_map<int,vector<int>> adj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adjA;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adjA[u].push_back(v);
            adjA[v].push_back(u);
        }
        return adjA;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size()+1;
        int M = edges2.size()+1;
        unordered_map<int,vector<int>> adjA = adj(edges1);
        unordered_map<int,vector<int>> adjB = adj(edges2);

        vector<int> markA(N,-1) ;
        markA[0]=0;
        int zeroMarkedCountA = 0;
        int oneMarkedCountA = 0;

        dfs(0,-1,adjA,markA,zeroMarkedCountA,oneMarkedCountA);


        vector<int> markB(M,-1) ;
        markB[0]=0;
        int zeroMarkedCountB = 0;
        int oneMarkedCountB = 0;

        dfs(0,-1,adjB,markB,zeroMarkedCountB,oneMarkedCountB);

        int maxFromB = max(zeroMarkedCountB,oneMarkedCountB);

        vector<int> res(N);
        for(int i=0;i<N;i++){
            res[i]= ((markA[i]==0 ? zeroMarkedCountA:oneMarkedCountA)+maxFromB);
        }
        return res;
    }
};