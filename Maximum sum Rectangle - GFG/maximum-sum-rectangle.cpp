//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int maxi = INT_MIN;
        for(int i=0;i<R;i++){
            vector<int> temp = M[i];
            
            int sum  = 0;
            int tempmaxi = INT_MIN;
            for(int tt=0;tt<temp.size();tt++){
                sum+=temp[tt];
                tempmaxi = max(tempmaxi,sum);
                if(sum<0) sum=0;
            }
            
            maxi = max(maxi,tempmaxi);
            
            for(int j=i+1;j<R;j++){
                int kk=0;
                for(auto it:M[j]) temp[kk++]+=it;
                
                sum  = 0;
                tempmaxi = INT_MIN;
                for(int tt=0;tt<temp.size();tt++){
                    sum+=temp[tt];
                    tempmaxi = max(tempmaxi,sum);
                    if(sum<0) sum=0;
                }
            
                maxi = max(maxi,tempmaxi);
            
            }
            
            
        }
        
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends