class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int n:nums){
         if(st.find(n-1)!=st.end()){
            continue;
         }
         else{
            int length=1;
            while(st.find(n+1)!=st.end()){
               length++;
               n=n+1;
            }
            longest=max(longest,length);
         }
        }
        return longest;
    }
};