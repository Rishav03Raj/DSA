class Solution {
public:
    string removeOuterParentheses(string& s) {
        int depth = 0;
        int write = 0; // write pointer

        for (int read = 0; read < s.size(); ++read) {
            if (s[read] == '(') {
                if (depth > 0) s[write++] = '(';
                depth++;
            } else {
                depth--;
                if (depth > 0) s[write++] = ')';
            }
        }

        s.resize(write); // shrink the string to only valid content
        return s;
    }
};
