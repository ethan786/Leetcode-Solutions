class Solution {
public:
    
    void solve(int i, vector<int> &a, vector<int> &com, vector<vector<int>> &ans, int t) {
        if(t == 0){
            ans.push_back(com);
            return;
        }
        
        for(int j = i; j < a.size(); j++){
            if(j > i and a[j] == a[j-1]) continue;
            if(a[j] > t) return;
            com.push_back(a[j]);
            solve(j+1,a,com,ans,t-a[j]);
            com.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> com;
        solve(0,a,com,ans,t);
        return ans;
    }
};