class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int src, vector<vector<int>>& a, vector<int> &vis, vector<int> path) {
        path.push_back(src);
        if(src == a.size() - 1) {
            ans.push_back(path);
            return;
        }
        vis[src] = 1;
        for(auto &i : a[src]) {
            if(!vis[i]) {
                dfs(i,a,vis,path);
            }
        }
        vis[src] = 0;
        path.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& a) {
        vector<int> vis(a.size(),0);
        vector<int> path;
        dfs(0,a,vis,path);
        return ans;
    }
};