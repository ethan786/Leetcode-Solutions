class Solution {
public:
    unordered_map<int,int> dp;
    int ways(int n){
        if(n == 1){
            return 0;
        }
        if(dp.find(n) != dp.end()) return dp[n];
        if(n%2 == 0){
            return dp[n] = 1 + ways(n/2);
        }else{
            return dp[n] = 1 + ways(3*n + 1);
        }
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>> v;
      
        for(int i=lo;i<hi+1;i++){
            v.push_back({ways(i),i});
        }
        
        sort(v.begin(),v.end());
        
        return v[k-1].second;
    }
};