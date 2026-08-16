class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // Can't split an odd total into two equal parts
        if (total % 2 != 0)
            return false;

        int target = total / 2;

        vector<bool> dp(target + 1, false);

        // Sum 0 is always possible:
        // choose nothing.
        dp[0] = true;

        for (int num : nums) {

            for (int w = target; w >= num; w--) {

                dp[w] = dp[w] || dp[w - num];
            }
        }

        return dp[target];
    }
};