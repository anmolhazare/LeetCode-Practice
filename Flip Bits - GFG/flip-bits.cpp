//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) zero++;
            else one++;
        }
        if(zero==0) return n;
        
        
        int count=0;
        int maxCount=INT_MIN;
        int l,r,lidx=0;
        for(int i=0;i<n;i++){
            
            if(a[i]==0) count++;
            else count--;
            
            if(count>maxCount){
                maxCount=count;
                l=lidx;
                r=i;
            }
            
            if(count<0){
                count=0;
                lidx=i+1;
            }
            
        }
        
        
        for(int i=l;i<=r;i++){
            if(a[i]==0) a[i]=1;
            else a[i]=0;
        }
        
        
        int k =0;
        for(int i=0;i<n;i++){
            if(a[i]==1) k++;
        }
        
        return k;
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends