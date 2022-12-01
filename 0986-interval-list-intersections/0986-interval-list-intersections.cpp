class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        
        for(auto it1:firstList){
            for(auto it2:secondList){
                int a = it1[0];
                int b = it1[1];
                
                int c = it2[0];
                int d = it2[1];
                
                if(c<=b){
                    int ab = max(a,c);
                    int ay = min(b,d);
                    if(ab<=ay) ans.push_back({ab,ay});
                }else if(a<=d){
                    int ab = max(a,c);
                    int ay = min(b,d);
                    if(ab<=ay) ans.push_back({ab,ay});
                }
                
                
            }
        }
        
        return ans;
        
    }
};