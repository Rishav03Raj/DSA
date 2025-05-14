class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sm;
        vector<int> can;
        sort(candidates.begin(), candidates.end()); // \U0001f511 Needed for handling duplicates
        f(candidates, can, sm, target, 0);
        return sm;
    }

    void f(vector<int>& cd, vector<int>& ds, vector<vector<int>>& st, int target, int ind) {
        if (target == 0) {
            st.push_back(ds);
            return;
        }

        for (int i = ind; i < cd.size(); i++) {
            if (i > ind && cd[i] == cd[i - 1]) continue; // skip duplicates
            if (cd[i] > target) break;

            ds.push_back(cd[i]);       // ✅ push before recursion
            f(cd, ds, st, target - cd[i], i + 1);
            ds.pop_back();             // backtrack
        }
    }
};
