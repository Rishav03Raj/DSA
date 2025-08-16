class prb{
public:
vector<int> size,parent;
    prb(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionSet(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }    
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        prb ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]){
                    ds.unionSet(i,j);
                }
                if(stones[i][1]==stones[j][1]){
                    ds.unionSet(i,j);
                }
            }
        }
       
        int ulp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                ulp++;
            }
        }
        return n-ulp;
    }
};