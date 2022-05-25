class Solution {
public:
    // O(n^2) dp solution
//     int maxEnvelopes(vector<vector<int>>& a) {
//         vector<int> dp(a.size(),1);
        
//         sort(a.begin(),a.end());
        
//         for(int i = 1; i < a.size(); ++i) {
//             for(int j = 0;j < i; j++) {
//                 if(a[i][0] > a[j][0] and a[i][1] > a[j][1]) {
//                     dp[i] = max(1 + dp[j], dp[i]);
//                 }
//             }
//         }
        
//         return *max_element(dp.begin(),dp.end());
        
//     }
    // O(nlogn) dp solution using lower bound
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& a) {
       sort(a.begin(),a.end(),cmp); 
       vector<int> lis;
        
       for(int i = 0;i<a.size();i++){
           int ele = a[i][1];
           
           int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
           
           if(idx >= lis.size()) lis.push_back(ele);
           else lis[idx] = ele;
       }
       
       return lis.size();   
    }
};