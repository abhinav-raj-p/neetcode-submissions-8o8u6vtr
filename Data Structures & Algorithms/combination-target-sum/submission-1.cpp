class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
     function<void(int,int)>sums=[&](int sum,int index)->void{
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(sum+nums[i]<=target){
                
                ds.push_back(nums[i]);
                sums(sum+nums[i],i);

                ds.pop_back();
                
            }
        }
     };
     sums(0,0);
     return ans;   
    }
};
