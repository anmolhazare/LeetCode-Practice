class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        vector<int> pre(nums.size());
        vector<int> post(nums.size());
        
        int current=1;
        for(int i=0;i<nums.size();i++){
            current*=nums[i];
            pre[i]=current;
            if(current==0) current=1;
        }
        
        current=1;
        for(int i=nums.size()-1;i>=0;i--){
            current*=nums[i];
            post[i]=current;
            if(current==0) current=1;
        }
        
        int maxi = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            maxi = max(max(maxi,nums[i]),max(pre[i],post[i]));
        }
        
        return maxi;
        
        
    }
};