class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        

        function<bool(int,int,int)>bk=[&](int r,int c,int index)->bool{
            if(index==word.size()){
                return true;
            }
            if(r<0 || r>=board.size() || c<0 || c>=board[0].size()){
                return false;
            }
            if(word[index]!=board[r][c]){
                return false;

            }

            char temp=board[r][c];
            board[r][c]='#';
            bool found=bk(r+1,c,index+1)||bk(r-1,c,index+1)||bk(r,c+1,index+1)||bk(r,c-1,index+1);
            board[r][c]=temp;
            return found;

          

            
        };
        for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(bk(i,j,0)){
                        return true;
                    }
                }
            }
            return false;
    }
};
