class Solution {
public:
bool isvalid(vector<vector<char>>& board,int r,int c,char ch){
    for(int i=0;i<9;i++){
     if (board[i][c] == ch || board[r][i] == ch)
                return false;    }
    int row=(r/3)*3,col=(c/3)*3;
    for(int i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            if(board[i][j]==ch)return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(isvalid(board,i,j,ch)){
                        board[i][j]=ch;
                        if(solve(board))return true;
                        board[i][j]='.';
                    }
                }
                
            return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};