class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string>ans;
        function<void(int,int)>bk=[&](int open,int close)->void{
            if(open==close && open==n){
                ans.push_back(ds);
                return;
            }
            if(open<n){
                ds.push_back('(');
                
                bk(open+1,close);

                ds.pop_back();
            }
            if(close<open){
                ds.push_back(')');
                
                bk(open,close+1);
                
                ds.pop_back();
            }


        };
        bk(0,0);
    return ans;
    }
    
};
