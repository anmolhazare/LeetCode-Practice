class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            if(seen.count(nums.at(i))==1){
                return nums.at(i);
            }
            seen[nums[i]]++;
        }
        return -1;
     
    }
};
