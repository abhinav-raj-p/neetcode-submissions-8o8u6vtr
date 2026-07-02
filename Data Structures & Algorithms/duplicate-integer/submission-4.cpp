#include<bits/stdc++.h>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int>se;
    for(int num:nums){
        if(se.count(num)){
            return true;
        }
        else{
            se.insert(num);
        }
    }return false;
    }
    
    
};