class Solution {
public:
    bool ans = false;
    void dfs(vector<vector<char>> &board,vector<vector<bool>> &vis,int row,int col,int idx,string st,int &mx){
        
        int n = board.size();
        int m = board[0].size();
        
        vis[row][col]=true;
        idx++;
        
        if(idx==st.length()){
            mx = max(mx,idx);
            return;
        }
        
        
        int delR[] = {-1,0,+1,0};
        int delC[] = {0,-1,0,+1};
        
        for(int i=0;i<4;i++){
            int nrow = row+delR[i];
            int ncol = col+delC[i];
            
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
              st[idx]==board[nrow][ncol]&&!vis[nrow][ncol]){
                dfs(board,vis,nrow,ncol,idx,st,mx);
            }
            
        }
        
        vis[row][col]=false;
        idx--;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&&!vis[i][j]){
                    int mx = 0;
                    dfs(board,vis,i,j,0,word,mx);
                    if(mx==word.size()) return true;
                }
            }
        }
        
        return false;
        
    }
};