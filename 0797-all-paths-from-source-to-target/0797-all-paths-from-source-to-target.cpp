class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int> adj[V];
        
        int pos=0;
        for(auto it:graph){
            adj[pos++]=it;
        }
        
        vector<vector<int>> ans;
        
        queue<pair<int,vector<int>>> pending;
        pending.push({0,{0}});
        while(pending.size()!=0){
            int node = pending.front().first;
            vector<int> vec = pending.front().second;
            pending.pop();
            
            if(node==V-1) ans.push_back(vec);
            
            for(auto it:adj[node]){
                vec.push_back(it);
                pending.push({it,vec});
                vec.pop_back();
            }
            
        }
        
        return ans;
        
    }
};