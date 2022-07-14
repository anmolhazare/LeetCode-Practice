class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                flag = false;
            } else if(s[i]==')' && st.empty()==false && st.top()=='(' ){
                st.pop();
                flag = true;
            }else if(s[i]=='}'&& st.empty()==false && st.top()=='{' ){
                st.pop();
                flag=true;
            }else if(s[i]==']'&& st.empty()==false && st.top()=='[' ){
                st.pop();
                flag = true;
            }else{
                flag=false;
                break;
            }
        }
        if(st.empty()==false){
            return false;
        }else{
         return flag;   
        }
        
    }
};
