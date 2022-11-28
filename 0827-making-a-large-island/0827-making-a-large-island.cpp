class DisjointSet{
	
	public:
        vector<int> rank,parent,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                
                int delR[] = {-1,0,+1,0};
                int delC[] = {0,-1,0,+1};
                
                for(int ind=0;ind<4;ind++){
                    int nrow = i+delR[ind];
                    int ncol = j+delC[ind];
                    
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&
                      grid[nrow][ncol]==1){
                        int u = i*n + j;
                        int v = nrow*n + ncol;
                        ds.unionBySize(u,v);
                    }
                    
                }
                
            }
        }
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                
                int delR[] = {-1,0,+1,0};
                int delC[] = {0,-1,0,+1};
                set<int> compos;
                for(int ind=0;ind<4;ind++){
                    int nrow = i+delR[ind];
                    int ncol = j+delC[ind];
                    
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&
                      grid[nrow][ncol]==1){
                        int v = nrow*n + ncol;
                        compos.insert(ds.findUltimateParent(v));
                        
                    }
                    
                }
                
                int size = 1;
                for(auto it:compos){
                    size+=ds.size[it];
                }
                
                maxi = max(maxi,size);
                
            }
        }
        
        for(int i=0;i<n*n;i++){
            maxi = max(maxi,ds.size[ds.findUltimateParent(i)]);
        }
        
        return maxi;
        
    }
};