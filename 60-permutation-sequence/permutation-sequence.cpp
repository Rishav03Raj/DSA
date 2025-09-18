class Solution {
private:
    int factorial(int n){
         int pr = 1;
        for(int i=2;i<=n;i++){
            pr*=i;
        }
        return pr;
    }
public:
    string getPermutation(int n, int k) {
         int f = factorial(n);
        vector<int> per(n);
       
        for(int i=0;i<n;i++){
            per[i]=i+1;
        }
        k--;
        string s = "";
        while(s.length()!=n){
            int window_size = factorial(n-s.length()-1);
            int ind = k/window_size;
            s+= to_string(per[ind]);
            per.erase(per.begin()+ind);
            k = k%window_size;
        }
        return s;
    }
};