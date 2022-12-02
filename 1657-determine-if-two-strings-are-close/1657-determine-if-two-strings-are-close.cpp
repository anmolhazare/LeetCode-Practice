class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        
       
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        
        if(word1==word2) return true;
        
        vector<int> ans1;
        map<int,int> mp;
        for(auto it:word1) mp[it]++;
        for(auto it:mp) ans1.push_back(it.second);
        sort(ans1.begin(),ans1.end());
        
        vector<int> ans2;
        map<int,int> mp2;
        for(auto it:word2) mp2[it]++;
        for(auto it:mp2) ans2.push_back(it.second);
        sort(ans2.begin(),ans2.end());
        
        for(auto it:mp){
            if(!(mp2.count(it.first)>0)) return false;
        }
        
        
        return ans1==ans2;
        
        
        
    }
};