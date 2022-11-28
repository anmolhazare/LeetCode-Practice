class DisjointSet{
	vector<int> rank,parent,size;
	public:
		DisjointSet(int n){
			rank.resize(n+1,0);
			size.resize(n+1,1);
			parent.resize(n+1);
			for(int i=0;i<=n;i++) parent[i]=i;
		}
		
		int findUltimateParent(int node){
			if(node==parent[node]){
				return node;
			}
			return parent[node] = findUltimateParent(parent[node]);
		}
		
		void unionByRank(int u,int v){
			
			int ulp_u = findUltimateParent(u);
			int ulp_v = findUltimateParent(v);
			
			if(ulp_u==ulp_v) return;
			
			if(rank[ulp_u] < rank[ulp_v]){
				parent[ulp_u] = ulp_v;
			}else if(rank[ulp_v] < rank[ulp_u]){
				parent[ulp_v] = ulp_u;
			}else{
				parent[ulp_v]=ulp_u;
				rank[ulp_u]++;
			}
		}
		
		void unionBySize(int u,int v){
			
			int ulp_u = findUltimateParent(u);
			int ulp_v = findUltimateParent(v);
			
			if(ulp_u==ulp_v) return;
			
			if(size[ulp_u] < size[ulp_v]){
				parent[ulp_u] = ulp_v;
				size[ulp_v] += size[ulp_u];
			}else{
				parent[ulp_v] = ulp_u;
				size[ulp_u] += size[ulp_v];
			}
			
		}
		
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        unordered_map<string,int> map;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail = details[i][j];
                if(map.find(mail)==map.end()){
                    map[mail]=i;
                }else{
                    ds.unionByRank(i,map[mail]);
                }
            }
        }
        
        vector<string> mergeMail[n];
        for(auto it:map){
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it:mergeMail[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        
        return ans;
    }
};