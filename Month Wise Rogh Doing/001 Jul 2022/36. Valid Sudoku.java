class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet seen = new HashSet();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if((!seen.add("Row"+i+board[i][j]))||(!seen.add("Coulmn"+j+board[i][j]))){
                    return false;
                }
                    if(!seen.add("Box"+((i/3)*3+(j/3))+board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}