class Solution {
public:
    int xrow=0,xcol=0;
    void dfs(vector<vector<int>> &land,vector<vector<bool>> &vis,int row,int col){
        
        vis[row][col]=true;
        int n = land.size();
        int m = land[0].size();
        
        int delR[] = {-1,0,+1,0};
        int delC[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++){
            
            int nrow = row+delR[i];
            int ncol = col+delC[i];
            
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
               land[nrow][ncol]==1&& !vis[nrow][ncol]){
                dfs(land,vis,nrow,ncol);
            }
            
        }
        
        xrow = max(xrow,row);
        xcol = max(xcol,col);
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    dfs(land,vis,i,j);
                    ans.push_back({i,j,xrow,xcol});
                    xcol=0;
                    xrow=0;
                }
            }
        }
        
        return ans;
    }
};