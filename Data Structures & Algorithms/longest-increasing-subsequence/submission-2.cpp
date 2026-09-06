class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int prevIndex) {

        // Base case
        if (i == n)
            return 0;

        // Check if already calculated
        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];

        // Skip current element
        int skip = solve(nums, i + 1, prevIndex);

        // Take current element
        int take = 0;

        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + solve(nums, i + 1, i);
        }

        // Store answer
        return dp[i][prevIndex + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1);
    }
};
