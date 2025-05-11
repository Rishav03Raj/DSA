class Solution {
public:
    double myPow(double x, int N) {
      double s=1;
     long long n = N;
      if(n<0){
        x = 1/x;
        n=-n;
      }
      while(n>0){
            if(n%2==1) s=s*x;
            x=x*x;
            n=n/2;
      }
      return s;
    }
};