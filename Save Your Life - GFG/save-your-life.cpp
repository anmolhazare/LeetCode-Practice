//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string s,char x[], int b[],int n){
          // code here    
          
          unordered_map<char,int> map;
          for(int i=0;i<n;i++) map[x[i]]=b[i];
          
          int current = 0;
          int ans = INT_MIN;
          string temp;
          string amit="";
          for(int i=0;i<s.length();i++){
              if(map.count(s[i])>=1) current+=map[s[i]];
              else current+=s[i];
              
              temp+=s[i];
              
              if(ans<=current){
                  ans=current;
                  amit=temp;
              }
              
              if(current<0){
                  current=0;
                  temp="";
              }
              
          }
          
          return amit;
          
          
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends