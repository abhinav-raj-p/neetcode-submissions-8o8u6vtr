class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        function<void(int, int)> dfs = [&](int index, int sum) {

            // Found a valid combination
            if (sum == target) {
                ans.push_back(ds);
                return;
            }

            // Went beyond target
            if (sum > target || index == nums.size()) {
                return;
            }

            // TAKE nums[index]
            ds.push_back(nums[index]);
            dfs(index, sum + nums[index]);
            ds.pop_back();

            // DON'T TAKE nums[index]
            dfs(index + 1, sum);
        };

        dfs(0, 0);

        return ans;
    }
};