//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        string modify (string s)
        {
            //code here.
            int i=0;
            int j=s.length()-1;
            
            while(i<j){
                while(i<j && s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'){
                    i++;
                }
                while(i<j && s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'){
                    j--;
                }
                
                if(i<j){
                    char ch = s[i];
                    s[i]=s[j];
                    s[j]=ch;
                }
                
                i++;
                j--;
                
            }
            
            return s;
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends