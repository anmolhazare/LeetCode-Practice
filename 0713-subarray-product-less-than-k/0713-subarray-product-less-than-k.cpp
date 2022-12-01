class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        long long current_sum = 1;
        long long current_len = 0;
        long long ans = 0;
        
        int left = 0;
        
        for(auto it:nums){
            
            current_sum*=it;
            current_len++;
            
            if(current_sum < k){
                ans+=current_len;
                continue;
            }
            
            while(left<nums.size() && current_sum >= k){
                current_sum/=nums[left++];
                current_len--;
            }
            
            ans+=current_len;
            
        }
        
        if((int)ans<0) return 0;
        return (int)ans;
    }
};