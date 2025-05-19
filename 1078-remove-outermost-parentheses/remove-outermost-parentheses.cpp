class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int o=0,c = 0,p=0;
        string st="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                o++;
            }
            else{
                c++;
            }
            if(o==c ){
               p=i+1;
               continue;
            }
            else if(i==p) continue;
            else{
                st+=s[i];
            }
        }
    return st;
    }
};