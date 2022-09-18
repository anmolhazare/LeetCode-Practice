class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> seen1;
        unordered_map<char,int> seen2;
        
        for(int i=0;i<ransomNote.length();i++){
            seen1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            seen2[magazine[i]]++;
        }
        bool ans = true;
        unordered_map<char,int>::iterator it = seen1.begin();
        while(it!=seen1.end()){
            if(seen2[it->first]<it->second){
                ans=false;
                break;
            }
            it++;
        }
        return ans;
    }
};
