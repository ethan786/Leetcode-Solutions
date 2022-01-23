class Solution {
public:
    
     int m = 1e9+7;
	    int solve(int i,string &s,vector<int> &dp){
	        if(i==s.size()){
	            return 1;
	        }
	        long long op1 = 0;
	        
	        if(dp[i] !=-1) return dp[i];
	       
	        if(s[i] != '0'){
	         op1 = solve(i+1,s,dp);
	        }
	        if(i < s.size()-1 and (s[i]-'0')*10 + (s[i+1]-'0') <=26 and (s[i]-'0') > 0){
	        op1 += solve(i+2,s,dp);
	        }
	        return dp[i] = op1;
	    }
    
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
		    vector<int> dp(s.size()+1,-1);
		    return solve(0,s,dp);
    }
};