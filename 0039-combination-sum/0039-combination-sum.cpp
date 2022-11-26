class Solution {
public:
    void helper(int idx,vector<int> &arr,vector<vector<int>> &ans,vector<int> &help,int target,int n){
        if(idx==n){
            if(target==0) ans.push_back(help);
            return;
        }
        
        if(arr[idx]<=target){
            help.push_back(arr[idx]);
            helper(idx,arr,ans,help,target-arr[idx],n);
            help.pop_back();
        }
        helper(idx+1,arr,ans,help,target,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> help;
        helper(0,candidates,ans,help,target,candidates.size());
        return ans;
    }
};