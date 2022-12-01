class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto it:nums){
            if(map.count(it)>0) return it;
            map[it]++;
        }
        return -1;
    }
};