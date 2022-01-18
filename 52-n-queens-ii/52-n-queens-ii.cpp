class Solution {
public:
    int c=0;
    void solve(int col,int n,vector<string> &board,vector<bool> &back,vector<bool> &upperdiagonal,vector<bool> &lowerdiagonal){
        //base case
        if(col == n){
            c++;
            return;
        }
        //traversing through every row 
        for(int row=0;row<n;row++){
            if(!back[row] and !upperdiagonal[n-1 + col - row] and !lowerdiagonal[col+row]){
                board[row][col] = 'Q';
                back[row] = 1;
                upperdiagonal[n-1 + col - row] = 1;
                lowerdiagonal[row+col] = 1;
                solve(col+1,n,board,back,upperdiagonal,lowerdiagonal);
                board[row][col] = '.';
                back[row] = 0;
                upperdiagonal[n-1 + col - row] = 0;
                lowerdiagonal[row+col] = 0;
            }
        }
        
    }
    int totalNQueens(int n) {
       vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        //using containers instead of is safe function
        //space optimized using bool vector instead of int
        // vector<int> back(n,0);
        // vector<int> upperdiagonal(2*n-1,0);
        // vector<int> lowerdiagonal(2*n-1,0);
        vector<bool> back(n,0);
        vector<bool> upperdiagonal(2*n-1,0);
        vector<bool> lowerdiagonal(2*n-1,0);
        solve(0,n,board,back,upperdiagonal,lowerdiagonal);
        return c; 
    
}
};