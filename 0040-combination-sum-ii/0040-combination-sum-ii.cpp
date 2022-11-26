class Solution {
public:
    void helper(int n,int target,vector<int>& temp,vector<int> &arr,vector<vector<int>> &ans,int index)
    {
       if(target==0)   {
           ans.push_back(temp);
           return;
       }
        
        for(int i=index;i<n;i++){
            if(i!=index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            
            temp.push_back(arr[i]);
            helper(n,target-arr[i],temp,arr,ans,i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(n,target,temp,candidates,ans,0);
        return ans;
    }
};