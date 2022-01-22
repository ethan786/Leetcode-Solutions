class Solution {
public:
    
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    for(char c = '1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            
                            if(solve(board)==true){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board,int r,int co,char c){
        // for row and col
         int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[r][i] == c) return false;
            if(board[i][co] == c) return false;
        }
        //for box
        int start_box_row = (r>=0 and r<3) ? r=0 : ((r>=3 and r<6) ? r = 3 : r = 6);
        int start_box_col = (co>=0 and co<3) ? c=0 : ((co>=3 and co<6) ? co = 3 : co = 6);
        //cout<<"row="<<start_box_row<<"col"<<start_box_col;
        for(int i = start_box_row;i<start_box_row+3;i++){
            for(int j = start_box_col;j<start_box_col+3;j++){
                if(board[i][j] == c) return false;
            }
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};