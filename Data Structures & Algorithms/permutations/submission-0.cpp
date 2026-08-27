class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int>used(nums.size()+1,0);

        function<void(int)>bk=[&](int index)->void{

            if(index==nums.size()){
                ans.push_back(ds);
                return;

            }

            for(int i=0;i<nums.size();i++){
                if(used[i]){
                    continue;
                }
                used[i]=1;
                ds.push_back(nums[i]);
                bk(index+1);

                used[i]=0;
                ds.pop_back();
            }
        };

        bk(0);
        return ans;
    }
};
