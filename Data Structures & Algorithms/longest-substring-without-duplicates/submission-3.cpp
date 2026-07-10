#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxLength=0;
        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                
                int length=(i-left)+1;
                maxLength=max(length,maxLength);
            }else{
                while(left<i){
                    st.erase(s[left]);
                    left++;
                    if(st.find(s[i])==st.end()){
                        st.insert(s[i]);
                        break;
                    }
            
            }
            }
            
        }
        return maxLength;
    }
};
