class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddcn = 0, prvcn = 0, ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] % 2 != 0) {
                oddcn++;
                prvcn = 0;
            }
            while (i < n && oddcn == k) {
                prvcn++;
                if (nums[i] % 2 != 0) {
                    oddcn--;
                }
                i++;
            }
            ans += prvcn;
            j++;
        }
        return ans;
    }
};