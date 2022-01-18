class Solution {
public:
    
    bool isSafe(int r,int c,vector<string> &board,int n){
        int dr = r;
        int dc = c;
        //backward direction
        while(c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }
        //upper diagonal
        r=dr;
        c=dc;
        while(r>=0 and c>= 0){
            if(board[r][c]=='Q') return false;
            c--;
            r--;
        }
        //downward diagonal
        r=dr;
        c=dc;
        while(r<n and c>= 0){
            if(board[r][c]=='Q') return false;
            c--;
            r++;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans,vector<string> &board,int n,int col){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(ans,board,n,col+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(ans,board,n,0);
        return ans;
    }
};
