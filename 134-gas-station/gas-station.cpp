class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0 , curr_gas = 0 , start_point = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            int diff = gas[i]-cost[i];
            total_gas += diff;
            curr_gas += diff;
            if(curr_gas<0){
                curr_gas=0;
                start_point = i+1;
            }
        }
        if(total_gas>=0) return start_point;
        else return -1;
    }
};