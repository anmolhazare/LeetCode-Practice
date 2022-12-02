class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int delR[] = {-1,0,+1,0,-1,+1,-1,+1};
                int delC[] = {0,+1,0,-1,-1,+1,+1,-1};
                int cnt = 0;
                
                for(int it=0;it<8;it++){
                    int nrow = i+delR[it];
                    int ncol = j+delC[it];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                      board[nrow][ncol]==1){
                        cnt++;
                    }
                }
                
                if(board[i][j]==1 && (cnt<2||cnt>3)) ans[i][j]=0;
                else if(board[i][j]==1 && (cnt==2||cnt==3)) ans[i][j]=1;
                else if(board[i][j]==0 && cnt==3) ans[i][j]=1;
                
            }
        }
        
        board=ans;
        
    }
};