class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        int temp;
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            seen[nums[i]]++;
            if(seen[nums[i]]==n){
                temp =  nums[i];
                break;
            }
        }
        return temp;
    }
};
