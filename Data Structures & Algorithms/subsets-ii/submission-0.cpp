class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        function<void(int)>bk=[&](int index)->void{
            ans.push_back(ds);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            bk(i+1);

            ds.pop_back();
            
        }
        
        };    
        sort(nums.begin(),nums.end());
        bk(0);
        return ans;
    
    }
};
