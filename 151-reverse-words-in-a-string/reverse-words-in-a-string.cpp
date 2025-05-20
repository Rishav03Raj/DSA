class Solution {
public:
   string reverseWords(string s) {
       string word="";
       vector<string>st;
     for(char c:s){
        if(c!=' '){
            word+=c;
        }
        else{
            st.push_back(word);
            word="";
        }
     }
     st.push_back(word);
     s="";
     for(int i=st.size()-1;i>0;i--){
        if(st[i]=="") continue;
        s+=st[i];
        s+=' ';
        
     }
     if(st[0]!="") 
        s+=st[0];
     if(s[s.length()-1]==' '){
        s.erase(s.length()-1,1);
     }
     return s;
    }
};
