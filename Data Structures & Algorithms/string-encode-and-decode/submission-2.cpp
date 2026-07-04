#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encodeString;
        for(auto &c:strs){
            encodeString+=to_string(c.size())+"#"+c;
        }
        return encodeString;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        size_t i=0;
        while(i<s.size()){
            size_t delimiter=s.find("#",i);
            string pos=s.substr(i,delimiter-i);
            int size=stoi(pos);
            string c=s.substr(delimiter+1,size);
            decoded.push_back(c);
            i=size+1+delimiter;
        }
        return decoded;
    }
};
