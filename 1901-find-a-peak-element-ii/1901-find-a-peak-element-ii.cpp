class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int delR[] = {-1,0,+1,0};
                int delC[] = {0,+1,0,-1};
                
                bool flag = true;
                
                for(int k=0;k<4;k++){
                    
                    int nrow = i+delR[k];
                    int ncol = j+delC[k];
                    
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                       mat[i][j]<mat[nrow][ncol]){
                        flag=false;
                    }
                    
                }
                
                if(flag==true){
                    return {i,j};
                }
                
            }
        }
        
        return {-1,-1};
        
    }
};