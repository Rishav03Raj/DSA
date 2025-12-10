class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size() , mod = 1e9 + 7;
        unordered_map<int,int> left,right;
        for(int i:nums) right[i]++;
        int ans = 0;
        for(int i:nums){
            right[i]--;
            int l = left[2*i] , r = right[2*i];
            ans = (ans + (1LL*l*r))  % mod; 
            left[i]++;

        }
        return ans;
    }
};