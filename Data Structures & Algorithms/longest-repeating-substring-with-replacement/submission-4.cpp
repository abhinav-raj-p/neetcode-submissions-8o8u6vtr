class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int freq[26]={0};
        int len=0;
        int window=0;
        int i=0;
        int ans=0;
        for(i=0;i<s.length();i++){
            
            freq[s[i]-'A']++;
            len=max(len,freq[s[i]-'A']);

            while(((i-left+1)-len)>k){
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;

    }
};
