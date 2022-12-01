class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long current_sum = 0;
        long long current_len = 0;
        long long ans = 0;
        
        int left = 0;
        
        for(auto it:nums){
            
            current_sum+=it;
            current_len++;
            
            if(current_sum*current_len < k){
                ans+=current_len;
                continue;
            }
            
            while(current_sum*current_len >= k){
                current_sum-=nums[left++];
                current_len--;
            }
            
            ans+=current_len;
            
        }
        
        return ans;
        
    }
};