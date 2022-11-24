//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>nums, int N, int target)
    {
        // code here
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends