class Solution {
public:
    
    bool ispossible(int i,vector<vector<int>>& s, vector<int>& n){
        for(int j=0;j<n.size();j++){
            if(s[i][j] > n[j]) return false;
        }
        return true;
    }
    
    int solve(int i,vector<int>& p, vector<vector<int>>& s, vector<int>& n){
        //base 
        if(i == s.size()){
            int sum = 0;
            for(int i=0;i<n.size();i++){
                sum += n[i] * p[i]; 
            }
            
            return sum;
        }
        if(ispossible(i,s,n)){
            for(int j=0;j<n.size();j++){
                n[j] -= s[i][j];
            }
            int op1 = s[i][s[0].size()-1] + solve(i,p,s,n);
            
            for(int j=0;j<n.size();j++){
                n[j] += s[i][j];
            }
            int op2 = solve(i+1,p,s,n);
            return min(op1,op2);
        }else{
            return solve(i+1,p,s,n);
        }
    }
    
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& n) {
        
        return solve(0,p,s,n);
    }
};