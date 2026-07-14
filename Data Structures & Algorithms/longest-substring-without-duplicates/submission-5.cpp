class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int left=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            
            while(st.contains(s[i])){
                st.erase(s[left]);
                left++;
            }
            
                
                st.insert(s[i]);
                len=max(len,i-left+1);
            

        }
        return len;
    }
};
