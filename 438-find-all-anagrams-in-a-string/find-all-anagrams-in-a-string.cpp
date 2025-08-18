#define pb push_back
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(),ps = p.length();
        unordered_map<char,int> given,curr;
        for(char c:p){
            given[c]++;
        }
        int i=0,j=0;
        vector<int> res;
        while(j<n){
            curr[s[j]]++;
            // if(given.find(s[i])!=given.end()){
                
            // }
            if(j-i+1 == ps){
                if(given == curr){
                    res.pb(i);
                }
                curr[s[i]]--;
                if(curr[s[i]]==0) curr.erase(s[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};