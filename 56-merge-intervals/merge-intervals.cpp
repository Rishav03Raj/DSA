class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;

        // Sort by start time
        sort(intervals.begin(), intervals.end());

        // Initialize with the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the last in ans
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
