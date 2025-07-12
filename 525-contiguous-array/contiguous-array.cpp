class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        // if not selected anything sum is already 0
        mp[0]= -1;
        int sm = 0,mxlen=0;
        for(int i=0;i<n;i++){
            sm+=(nums[i]==0)?-1:1;
            if(mp.find(sm)!=mp.end()){
                mxlen = max(mxlen,i-mp[sm]);
            }
            else{
                mp[sm]=i;
            }
        }
        return mxlen;
    }
};