class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and avoid overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // 4. Check overflow after each step
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return static_cast<int>(sign * result);
    }
};
