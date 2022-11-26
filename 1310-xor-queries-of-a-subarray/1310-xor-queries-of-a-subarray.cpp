class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xo ;
        int hu = 0;
        for(auto it:arr){
            hu^=it;
            xo.push_back(hu);
        }
        
        vector<int> ans;
        
        for(auto it:queries){
            int temp = xo[it[1]];
            if(it[0]>0) temp^=(xo[it[0]-1]);
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};