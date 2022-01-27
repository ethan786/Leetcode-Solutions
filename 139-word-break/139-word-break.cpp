class Solution {
public:
    
    bool isPresendInDict(string &find,vector<string>& wordDict){
        for(string x : wordDict){
            if(x==find){
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);//dp[i] means is string till ith index in string s is present                                    // in word dist or not and befor that we are checking is 
                                   //dp[previous substr index present or not]
        //example -> dp[4] = true for {leet} now we are at dp[8] for {code} 
        // if dp[4] is true and code is present in worddist then dp[8] = true;
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]){
                    string find = s.substr(j,i-j);
                    if(isPresendInDict(find,wordDict)){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};