class Solution {
vector<int>parent,size;

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionSet(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return ;
        else{
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_v]+=size[ulp_u];
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        int cn=0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(findParent(u)==findParent(v)) {
                cn++;
                continue;
            }
            unionSet(u,v); 
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(findParent(i));
        }
        if(s.size()-1<=cn) return s.size()-1;
        else return -1;
    }
};