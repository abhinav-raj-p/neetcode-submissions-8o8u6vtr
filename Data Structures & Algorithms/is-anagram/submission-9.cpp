#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={0};
        if(s.length()!=t.length()){
            return false;
        }
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:t){
            if(freq[c-'a']==0){
                return false;
            }
            freq[c-'a']--;
        }
        return true;
    }

};
