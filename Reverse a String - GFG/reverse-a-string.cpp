//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

void helper(string &st,int start,int end){
    if(start>=end) return;
    char temp = st[start];
    st[start]=st[end];
    st[end]=temp;
    helper(st,start+1,end-1);
}

string reverseWord(string str){
    
  //Your code here
  helper(str,0,str.length()-1);
  return str;
  
  
}

