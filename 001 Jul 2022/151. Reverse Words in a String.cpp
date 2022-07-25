class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                if(temp.length()!=0){
                  st.push(temp);  
                  temp="";
                }
            }
        }
        if(temp.length()!=0){
         st.push(temp);   
        }
        string yash;
        while(st.size()!=0){
            yash+=st.top();
            st.pop();
            if(st.size()!=0){
                yash+=" ";
            }
        }
        return yash;
    }
};
