class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        for(auto c:operations){
            if(c=="X++") ans++;
            else if(c=="++X") ++ans;
            else if(c=="--X") --ans;
            else ans-- ;
     
        }
        return ans;
    }

};