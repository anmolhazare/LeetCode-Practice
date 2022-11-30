class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> map;
    for(auto it:arr) map[it]++;
    unordered_map<int,int> mp;
    for(auto it:map){
        if(mp.count(it.second)>0) return false;
        mp[it.second]++;
    }
    return true;
        
    }
};