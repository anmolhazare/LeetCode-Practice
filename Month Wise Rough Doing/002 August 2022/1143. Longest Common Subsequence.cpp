class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        
    
        //First Row Fill up
        for(int j=text2.length();j>=0;j--) dp[0][j]=0;
        //First Col Fill up
        for(int i=text1.length();i>=0;i--) dp[i][0]=0;
        
        //Then fill the all cells  row wise
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                //If first characeter match or not
                if(text1[text1.length()-i]==text2[text2.length()-j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    int a = dp[i-1][j];
                    int b = dp[i][j-1];
                    int c = dp[i-1][j-1];
                    dp[i][j] = max(a,max(b,c));
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};
