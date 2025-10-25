class Solution {
public:
    int totalMoney(int n) {
        int sm = 0,st=1,cr=1,cn=1;
        while(n){
            if(cn==8){
                st++;
                cr=st;
                cn=1;
            }
            sm+=cr;
            cr++;
            cn++;
            n--;
        }
        return sm;
    }
};