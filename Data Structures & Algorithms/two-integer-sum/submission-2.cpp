class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<=nums.size();i++){
            int complement=target-nums[i];
            if(!mp.contains(complement)){
                mp[nums[i]]=i;
            }
            else{
                return {mp[complement],i};
            }
        }
    }
};
