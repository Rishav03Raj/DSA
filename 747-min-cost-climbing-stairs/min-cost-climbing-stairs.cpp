class Solution {
private:
    int f(int n,vector<int> &cost){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        int fr = f(n-1,cost);
        int sc = f(n-2,cost)+cost[n];
        return min(fr,sc);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2;i<n;i++){
            cost[i]+=min(cost[i-1],cost[i-2]);
        }

    return min(cost[n-1],cost[n-2]);
    }
};