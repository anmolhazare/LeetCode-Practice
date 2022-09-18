class Solution {
public:
    string helper(string s){
        string temp;
        for(int i=0;i<s.length();i++){
            if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)) temp+=s[i];
        }
        return temp;
    }
    bool palinHelper(string s){
        int i=0;
        int j=s.length()-1;
        while(j>i){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return palinHelper(helper(s));
    }
};
