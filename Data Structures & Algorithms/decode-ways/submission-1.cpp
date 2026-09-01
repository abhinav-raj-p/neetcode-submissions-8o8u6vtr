class Solution {
public:
    int numDecodings(string s) {
    int n = s.size();

    int next1 = 1; // dp[n]
    int next2 = 0; // dp[n+1]

    for (int i = n - 1; i >= 0; i--) {

        int current = 0;

        if (s[i] != '0') {

            // Take one digit
            current = next1;

            // Take two digits
            if (i + 1 < n &&
                (s[i] == '1' ||
                 (s[i] == '2' && s[i + 1] <= '6'))) {

                current += next2;
            }
        }

        // Shift
        next2 = next1;
        next1 = current;
    }

    return next1;
}

};
