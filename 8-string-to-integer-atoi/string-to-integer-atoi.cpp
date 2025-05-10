class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0,a=1;
        string st = "";
        long long b ;
        while(s[i]==' ') i++;
        if(s[i]=='-'){ a*=-1;i++;}
        else if(s[i]=='+') i++;
        while(s[i]=='0') i++;
        for(i;i<n;i++){
            if(isdigit(s[i])) st+=s[i];
            else break;
        }

        if (st.empty()) return 0;

          try {
        b = stoll(st);
    } catch (...) {
        // In case it still overflows (just for safety)
        return (a == 1) ? INT_MAX : INT_MIN;
    }

    b *= a;
    if (b > INT_MAX) return INT_MAX;
    if (b < INT_MIN) return INT_MIN;
    return static_cast<int>(b);
 }

};