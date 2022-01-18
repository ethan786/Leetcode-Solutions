// class Solution {
// public:
    
//     bool isSafe(int r,int c,vector<string> &board,int n){
//         int dr = r;
//         int dc = c;
//         //backward direction
//         while(c>=0){
//             if(board[r][c]=='Q') return false;
//             c--;
//         }
//         //upper diagonal
//         r=dr;
//         c=dc;
//         while(r>=0 and c>= 0){
//             if(board[r][c]=='Q') return false;
//             c--;
//             r--;
//         }
//         //downward diagonal
//         r=dr;
//         c=dc;
//         while(r<n and c>= 0){
//             if(board[r][c]=='Q') return false;
//             c--;
//             r++;
//         }
//         return true;
//     }
    
//     void solve(vector<vector<string>> &ans,vector<string> &board,int n,int col){
//         //base case
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
        
//         for(int row=0;row<n;row++){
//             if(isSafe(row,col,board,n)){
//                 board[row][col] = 'Q';
//                 solve(ans,board,n,col+1);
//                 board[row][col] = '.';
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i] = s;
//         }
//         solve(ans,board,n,0);
//         return ans;
//     }
// };



class Solution {
public:
    //time complexity optimized
    
    void solve(int col,int n,vector<vector<string>> &ans,vector<string> &board,vector<bool> &back,vector<bool> &upperdiagonal,vector<bool> &lowerdiagonal){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }
        //traversing through every row 
        for(int row=0;row<n;row++){
            if(!back[row] and !upperdiagonal[n-1 + col - row] and !lowerdiagonal[col+row]){
                board[row][col] = 'Q';
                back[row] = 1;
                upperdiagonal[n-1 + col - row] = 1;
                lowerdiagonal[row+col] = 1;
                solve(col+1,n,ans,board,back,upperdiagonal,lowerdiagonal);
                board[row][col] = '.';
                back[row] = 0;
                upperdiagonal[n-1 + col - row] = 0;
                lowerdiagonal[row+col] = 0;
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
        //using containers instead of is safe function
        //space optimized using bool vector instead of int
        // vector<int> back(n,0);
        // vector<int> upperdiagonal(2*n-1,0);
        // vector<int> lowerdiagonal(2*n-1,0);
        vector<bool> back(n,0);
        vector<bool> upperdiagonal(2*n-1,0);
        vector<bool> lowerdiagonal(2*n-1,0);
        solve(0,n,ans,board,back,upperdiagonal,lowerdiagonal);
        return ans;
    }
};