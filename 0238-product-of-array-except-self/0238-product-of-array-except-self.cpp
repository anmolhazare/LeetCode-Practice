class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        
        long long curr = 1;
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            pre[i]=curr;
            curr*=nums[i];
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            suf[i]=curr;
            curr*=nums[i];
        }
        
        for(int i=0;i<n;i++){
            ans.push_back(pre[i]*suf[i]);
        }
        
        return ans;
        
    }
};