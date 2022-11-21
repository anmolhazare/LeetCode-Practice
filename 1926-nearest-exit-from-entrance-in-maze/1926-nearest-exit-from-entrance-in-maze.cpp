class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[entrance[0]][entrance[1]]=true;
        
        queue<pair<int,pair<int,int>>> pending;
        
        
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int nrow = entrance[0]+delRow[i];
                int ncol = entrance[1]+delCol[i];
                
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                   maze[nrow][ncol]=='.' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    pending.push({1,{nrow,ncol}});
                }
            }
        
        while(pending.size()!=0){
            
            int levl = pending.front().first;
            int row  =pending.front().second.first;
            int col = pending.front().second.second;
            pending.pop();
            
            if(row==0||col==0||row==n-1||col==m-1){
                return levl;
            }
            
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];
                
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                   maze[nrow][ncol]=='.' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    pending.push({levl+1,{nrow,ncol}});
                }
            }
            
            
        }
        
        return -1;
        
    }
};