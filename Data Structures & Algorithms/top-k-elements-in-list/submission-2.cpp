#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency of each number
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto x:freq){
            pq.push({x.second,x.first});
        }
        vector<int>result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
