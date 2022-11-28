class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int ans = 0;
        unordered_map<int,int> map;
        int current_sum = 0;
        for(int i=0;i<nums.size();i++){
            current_sum+=nums[i];
            if(map.find(current_sum-K)!=map.end()){
                ans+=map[current_sum-K];
            }
            if(current_sum==K) ans++;
            map[current_sum]++;
        }
        
        return ans;
    }
};