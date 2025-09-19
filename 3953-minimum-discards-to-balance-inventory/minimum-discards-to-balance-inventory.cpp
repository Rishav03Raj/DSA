class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        set<int> idx;
        int j = 0; int ans = 0;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            // int cnt = i-j+1;
            while(i-j+1>w){
                if(idx.find(j)!=idx.end()){
                    idx.erase(j);
                    freq[arrivals[j]]--;
                    j++;
                }
                else{
                    j++;
                }
            }
            freq[arrivals[i]]++;
            if(freq[arrivals[i]]>m){
                freq[arrivals[i]]--;
                ans++;
            }
            else{
                idx.insert(i);
                
            }
        }
        return ans;
    }
};