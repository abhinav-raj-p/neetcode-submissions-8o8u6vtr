class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);

        function<int(int)> solve = [&](int amount) -> int {

            // Base case
            if (amount == 0) {
                return 0;
            }

            // Impossible
            if (amount < 0) {
                return INT_MAX;
            }

            // Already calculated
            if (dp[amount] != -1) {
                return dp[amount];
            }

            int ans = INT_MAX;

            for (int coin : coins) {

                int result = solve(amount - coin);

                if (result != INT_MAX) {
                    ans = min(ans, 1 + result);
                }
            }

            // Store the answer
            dp[amount] = ans;

            return ans;
        };

        int ans = solve(amount);

        return ans == INT_MAX ? -1 : ans;
    }
};
