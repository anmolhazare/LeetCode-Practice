class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            seen[nums[i]]++;
        }
        int temp=1;
        while(temp>0){
            if(seen.count(temp)!=1){
                break;
            }
            temp++;
        }
        return temp;
    }
};