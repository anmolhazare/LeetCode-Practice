class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        
        unordered_map<char,int> map;
        vector<string> vc(s.length(),"");
        
        int k=0;
        
        for(auto i:s){
            if(map.count(i)>=1){
                for(int p=map[i]+1;p<k;p++){
                    vc[map[i]]+=vc[p];
                    for(auto z:vc[p]) map[z]=map[i];
                    vc[p]="";
                }
                vc[map[i]]+=i;
                k=map[i]+1;
            }else{
                map[i]=k;
                vc[k]+=i;
                k++;
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(vc[i].length()>0) ans.push_back(vc[i].length());
        }
        
        
        return ans;
        
    }
};