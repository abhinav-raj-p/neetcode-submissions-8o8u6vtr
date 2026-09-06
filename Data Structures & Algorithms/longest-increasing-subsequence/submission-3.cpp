class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // prevIndex ranges from -1 to n-1
        // Hence n+1 columns
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // i goes backwards
        for (int i = n - 1; i >= 0; i--) {

            for (int prevIndex = -1; prevIndex < i; prevIndex++) {

                // Choice 1: Skip
                int skip = dp[i + 1][prevIndex + 1];

                // Choice 2: Take
                int take = 0;

                if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][prevIndex + 1] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};
