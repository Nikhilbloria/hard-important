class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                //store every indices of i and j where we found number ;
                string row = string(1, board[i][j]) +"_row"+ to_string(i);
                string col = string(1, board[i][j]) + "_col"+ to_string(j);
                string grid = string(1, board[i][j]) + "_grid"+ to_string(i/3)+ " "+ to_string(j/3);
                //check if it is already present
                if(st.find(row)!=st.end()||st.find(col)!=st.end()||st.find(grid)!=st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(grid);
            }
        }return true;
    }
};