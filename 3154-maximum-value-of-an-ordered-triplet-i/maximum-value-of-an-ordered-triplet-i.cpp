class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long mx = 0;
        
        // Suffix max: store the max value from index k to n-1
        vector<int> suffixMax(n, 0);
        suffixMax[n - 1] = nums[n - 1];
        
        for (int k = n - 2; k >= 0; k--) {
            suffixMax[k] = max(suffixMax[k + 1], nums[k]);
        }

        // Prefix max: track the maximum nums[i] seen so far
        int prefixMax = nums[0];

        // Iterate over j (middle element)
        for (int j = 1; j < n - 1; j++) {
            if (j + 1 < n) {
                long long value = 1LL * (prefixMax - nums[j]) * suffixMax[j + 1];
                mx = max(mx, value);
            }
            prefixMax = max(prefixMax, nums[j]); // Update prefix max
        }

        return mx;
    }
};
