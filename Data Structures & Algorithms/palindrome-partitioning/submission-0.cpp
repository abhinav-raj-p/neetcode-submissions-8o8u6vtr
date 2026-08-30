class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        function<bool(int,int)>isPalindrome=[&](int index,int i)->bool{
            while(index<i){
                if(s[index]!=s[i]){
                    return false;
                }
                index++;
                i--;
            }
            return true;
        };

        function<void(int)>bk=[&](int index)->void{

            if(index==s.size()){
                ans.push_back(ds);
                return;
            }
            for(int i=index;i<s.size();i++){
                if(!isPalindrome(index,i)){
                    continue;
                }

                ds.push_back(s.substr(index,(i-index)+1));
                bk(i+1);

                ds.pop_back();


            }

        };

        bk(0);
        return ans;
    }
};
