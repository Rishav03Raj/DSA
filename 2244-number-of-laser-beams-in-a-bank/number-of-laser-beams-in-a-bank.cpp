class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        int total = 0;
        int prv = 0 , curr = 0;
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1') cnt++;
            }
            if(cnt!=0){
                prv = curr;
                curr = cnt;
                total += prv * curr;
            }
        }
    return total;
    }
};