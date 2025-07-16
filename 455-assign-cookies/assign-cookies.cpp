class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gn = g.size();
        int sn = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,c=0;
        while(i<gn && j<sn){
            if(g[i]<=s[j]){
                c++;i++;j++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};