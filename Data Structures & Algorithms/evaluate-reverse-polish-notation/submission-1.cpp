class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string c:tokens){
            if(c=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a+b;
                st.push(c);
            }
            else if(c=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b-a;
                st.push(c);
            }
            else if(c=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a*b;
                st.push(c);
            }
            else if(c=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b/a;
                st.push(c);
            }
            else{
               int n=stoi(c);
               st.push(n);
            }
            
        }
        return st.top();
    }
};
