class Solution {
public:
    
    //memoziation
    int solve(int n,vector<int> &v){
        // base case
        if(n==0){
            return 1;
        }else if(n<0){
            return 0;
        }
        //Checking previously solved or not for n
        if(v[n]!=-1) return v[n];
        
        int op1 = solve(n-1,v);// jump 1 step
        int op2 = solve(n-2,v);// jump 2 step
        return v[n] = op1+op2;// storing and returing the answer
    }
    
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        solve(n,v);
        return v[n];
    }
    
};