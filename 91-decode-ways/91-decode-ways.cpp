class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        //base case
        if(n==1 and (s[0]-'0') > 0){
            return 1;
        }else if(n==1 and (s[0]-'0') == 0) return 0;
        vector<int> dp(n,0);
        dp[0] = (s[0]-'0' > 0 ? 1 : 0);//hard coding 
        for(int i=1;i<n;i++){
            int single_digit = s[i]-'0';
            int two_digit = (s[i-1]-'0')*10 + single_digit;
            if(single_digit > 0 ) dp[i] = dp[i-1]; //base condition
            if(i>=2 and two_digit >= 10 and two_digit <= 26){
                dp[i] += dp[i-2];
            }
            if(i==1 and two_digit >= 10 and two_digit <= 26){
                dp[i] += 1;
            }
        }
        return dp[n-1];
    }
};