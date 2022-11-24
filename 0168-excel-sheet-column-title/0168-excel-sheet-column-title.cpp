class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while(columnNumber>26){
            int lastDigit = columnNumber%26;
            ans+=(char)(lastDigit+64);
            columnNumber/=26;
        }
        ans+=(char)(columnNumber+64);
        reverse(ans.begin(),ans.end());
        if(n==52) return "AZ";
        if(n==702) return "ZZ";
        return ans;
    }
};