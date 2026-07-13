class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        
        int count[26]={0};
        int maxFreqeuncy=0;
        int ans=0;

        for(int i=0;i<s.length();i++){
            count[s[i]-'A']++;
            maxFreqeuncy=max(maxFreqeuncy,count[s[i]-'A']);
            while((i-left+1)-maxFreqeuncy>k){
                count[s[left]-'A']--;
                left++;

            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
