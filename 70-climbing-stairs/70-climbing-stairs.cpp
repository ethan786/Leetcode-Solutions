class Solution {
public:
    // recursion
    // int c=0;
    // void solve(int n){
    //     if(n==0){
    //         c++;
    //         return;
    //     }else if(n<0){
    //         return;
    //     }
    //      solve(n-1);
    //      solve(n-2);
    // }
    // int climbStairs(int n) {
    //     solve(n);
    //     return c;
    // }
    
    //memoziation
//     int solve(int n,vector<int> &v){
//         if(n==0){
//             return 1;
//         }else if(n<0){
//             return 0;
//         }
//         if(v[n]!=-1) return v[n];
//         int op1 = solve(n-1,v);
//         int op2 = solve(n-2,v);
//         return v[n] = op1+op2;
//     }
    
//     int climbStairs(int n) {
//         vector<int> v(n+1,-1);
//         solve(n,v);
//         return v[n];
//     }
    int climbStairs(int n) {
         //tabulation using variable as we know that we only need previous 2 values toh generate solution
        if(n==1||n==2){
            return n;
        }
        int a = 1,b=2;
        for(int i=3;i<=n;i++){
            int c = a+b;
            a = b;
            b=c;
        }
        return b;
    }
    
};