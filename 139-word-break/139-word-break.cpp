class Solution {
public:
    
    bool ispresent(string& find,vector<string> &b){
    for(auto i : b){
        if(i == find){
            return true;
        }
    }
    return false;
    }
    
    
    bool wordBreak(string s, vector<string>& b) {
        int n = s.size();

    vector<bool> dp(n+1,false);
    dp[0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0;j < i; j++){
            if(dp[j]){
                string find = s.substr(j,i-j);
                if(ispresent(find,b)){
                    dp[i] = true;
                }
            }
        }
    }
    return dp[n];
    }
};