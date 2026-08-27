class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;

        function<void(int,int)>bk=[&](int index,int sum)->void{
            if(sum==target){
                ans.push_back(ds);
                return;
            }
            for(int i=index;i<candidates.size();i++){
                if(i>index && candidates[i]==candidates[i-1]){
                    continue;
                }
                if(sum+candidates[i]<=target){
                    ds.push_back(candidates[i]);
                    bk(i+1,sum+candidates[i]);

                    ds.pop_back();
                }
            }

        };

        sort(candidates.begin(),candidates.end()); 
        bk(0,0);
        return ans;

    }
};
