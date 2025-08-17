class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isflip(n,false);
        int flipcntfrompast = 0;
        int flip = 0;
        for(int i=0;i<n;i++){
            if(i>=k && isflip[i-k]){
                flipcntfrompast--;
            }
            if(flipcntfrompast % 2 == nums[i]){ // tells to flip if cond satisfied
                if(i+k>n){
                    return -1;
                }
                flipcntfrompast++;
                isflip[i]=true;
                flip++;
            }
        }
        return flip;
    }
};