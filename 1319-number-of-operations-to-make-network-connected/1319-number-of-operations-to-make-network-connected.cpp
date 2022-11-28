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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        
        int extra = 0;
        int compo = 0;
        
            for(auto it:connections){
                int u = it[0];
                int v = it[1];
                if(ds.findUltimateParent(u)==ds.findUltimateParent(v)){
                    extra++;
                }else{
                    ds.unionByRank(u,v);
                }
            }
        
        for(int i=0;i<n;i++){
            if(i==ds.findUltimateParent(i)) compo++;
        }
        
        int ans = compo-1;
        if(extra>=ans) return ans;
        else return -1;
    }
};