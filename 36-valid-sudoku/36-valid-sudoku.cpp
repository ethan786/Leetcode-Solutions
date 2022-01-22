class Solution {
public:
    
    bool solve(vector<vector<char>>& board,int r,int c,char ch){
        for(int i=0;i<9;i++){
                if(board[i][c]==ch) return false;
                if(board[r][i]==ch) return false;
        }
        //for box check
        int sr = (r>=0 and r<3) ? r=0 : ((r>=3 and r<6) ? r = 3 : r = 6); //sr-?start_row of box grid 3*3ok
        int sc = (c>=0 and c<3) ? c=0 : ((c>=3 and c<6) ? c = 3 : c = 6); 
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    board[i][j] = '.';
                    if(solve(board,i,j,ch) == false) return false;
                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
    
};