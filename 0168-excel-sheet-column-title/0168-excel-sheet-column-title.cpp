class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while(columnNumber!=0){
            int lastDigit = columnNumber%26;
            if(lastDigit==0) lastDigit=26;
            ans+=(char)(lastDigit+64);
            columnNumber/=26;
            if(lastDigit==26) columnNumber--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};