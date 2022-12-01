class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxi = 1;
        
        for(auto it:nums){
            map[it]++;
            maxi=max(maxi,map[it]);
        }
        
        int ans = INT_MAX;
        vector<int> arr;
        for(auto it:map){
            if(it.second==maxi) arr.push_back(it.first);
        }
        
        
        for(int i=0;i<arr.size();i++){
            int left = 0;
            int a=-1;
            int b=-1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]==arr[i] && a==-1) a=left;
                if(nums[right]==arr[i] && b==-1) b=right;
                
                if(a==-1) left++;
                if(b==-1) right--;
                
                if(a!=-1 && b!=-1) break;
                
            }
            
            
            ans = min(ans,(b-a));
            
        }
        
        if(ans<=0) return 1;
        
        return ans+1;
        
    }
};