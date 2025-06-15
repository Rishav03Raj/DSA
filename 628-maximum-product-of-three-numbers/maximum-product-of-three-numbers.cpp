class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mx=INT_MIN,smax=INT_MIN,tmax=INT_MIN,mn=INT_MAX,smn=INT_MAX;
        for(int i:nums){
            if(i>mx){
                tmax=smax;
                smax=mx;
                mx=i;
            }
            else if(i>smax){
                tmax=smax;
                smax=i;
            }
            else if(i>tmax){
                tmax=i;
            }
            if(i<mn){
                smn=mn;
                mn=i;
            }
            else if(i<smn){
                smn=i;
            }
        }
        return max(mx*smax*tmax,mn*smn*mx);
    }
};