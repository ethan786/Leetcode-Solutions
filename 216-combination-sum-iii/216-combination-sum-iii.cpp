class Solution {
public:
    vector<vector<int>> ans;
    int sum = 0;
    void solve(int i, int k, int n, vector<int>& vis,vector<int>& com){
        //base case
        if(com.size() > k || sum > n || i > 10) return;
        if(i == 10){
            if(sum == n and com.size() == k){
                ans.push_back(com);
            }
            return;
        }
        
        vis[i] = 1;
        com.push_back(i);
        sum += i;
        solve(i+1,k,n,vis,com);
        vis[i] = 0;
        com.pop_back();
        sum -= i;
        solve(i+1,k,n,vis,com);
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vis(10,0);
        vector<int> com;
        solve(1,k,n,vis,com);
        return ans;
    }
};
// 1 2 3 4 5 6 7 8 9 
// 1 1 0 0 0 0 0 0 0
// sum = 6