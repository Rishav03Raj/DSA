class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<bool> isflip(n,false);
        deque<int> dq;
        int flipcntfrompast = 0;
        int flip = 0;
        for(int i=0;i<n;i++){
            if(i>=k){
                flipcntfrompast-=dq.front();
                dq.pop_front();
            }
            if(flipcntfrompast % 2 == nums[i]){ // tells to flip if cond satisfied
                if(i+k>n){
                    return -1;
                }
                flipcntfrompast++;
                dq.push_back(1);
                flip++;
            }else{
                dq.push_back(0);
            }
        }
        return flip;
    }
};