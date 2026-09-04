class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<int> dp(n, -1);

        function<bool(int)> solve = [&](int i) -> bool {

            if (i == n)
                return true;

            if (dp[i] != -1)
                return dp[i];

            for (int j = i; j < n; j++) {

                string word = s.substr(i, j - i + 1);

                if (dict.count(word)) {

                    if (solve(j + 1))
                        return dp[i] = true;
                }
            }

            return dp[i] = false;
        };

        return solve(0);
    }
};
