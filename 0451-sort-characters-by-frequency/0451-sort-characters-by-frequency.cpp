class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> ans;
        
        unordered_map<char,int> map;
        for(auto i:s){
            map[i]++;
        }
        
        for(auto i:map){
            ans.push_back({i.second,i.first});
        }
        
        string tt;
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        
        
        for(auto i:ans){
           int kl = i.first;
            while(kl--){
                tt+=(i.second);
            }
        }
        
        return tt;
    }
};