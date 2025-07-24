class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int>prv (n2 + 1, 0),cur(n2+1,0);
    
        for (int j = 0; j <= n2; j++) {
            prv[j] = j;
        }
        for (int i = 1; i <= n1; i++) {
             cur[0] = i;
            for (int j = 1; j <= n2; j++) {
                if (s1[i-1] == s2[j-1])
                   cur[j] = prv[j - 1];
                else {
                     cur[j] =
                               1 + min(prv[j],
                                       min(cur[j - 1], prv[j - 1]));
                }
            }
               prv = cur;
        }
        return prv[n2];
    }

        // int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        //     if (i < 0)
        //         return j + 1;
        //     if (j < 0)
        //         return i + 1;
        //     if (dp[i][j] != -1)
        //         return dp[i][j];

        //     if (s1[i] == s2[j])
        //         return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2, dp);
        //     else {
        //         return dp[i][j] = 1 + min(f(i, j - 1, s1, s2, dp),
        //                                   min(f(i - 1, j, s1, s2, dp),
        //                                       f(i - 1, j - 1, s1, s2, dp)));
        //     }
        // }
    };