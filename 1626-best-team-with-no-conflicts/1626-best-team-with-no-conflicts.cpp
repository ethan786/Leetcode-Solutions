class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>> p;
        for(int i=0;i<s.size();i++){
            p.push_back({a[i],s[i]});
        }
        int n = s.size();
        sort(p.begin(),p.end());
        //dp solution
        vector<int> dp(n,0);
        dp[0] = p[0].second;
        for(int i=0;i<n;i++){
            dp[i] = p[i].second;
            for(int j=0;j<i;j++){
                if(p[i].second >= p[j].second){
                    dp[i] = max(dp[i],dp[j] + p[i].second);
                }
            }
        }
        int ans = -3178;
        for(int i=0;i<n;i++){
            ans = max(dp[i],ans);
        }
        return ans;
    }
};