#include<bits/stdc++.h>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int>se;
    se.insert(nums.begin(),nums.end());
    if(se.size()==nums.size()){
        return false;
    }
    else{
        return true;
    }
    }
    
};