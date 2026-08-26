class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        
        function<void(int)> backtrack = [&](int index) -> void {
            if(nums.size()==index){
            ans.push_back(ds);
            return;
        }
            ds.push_back(nums[index]);
            backtrack(index+1);

            ds.pop_back();

            backtrack(index+1);


        };
        backtrack(0);
        return ans;
        

    }
};
