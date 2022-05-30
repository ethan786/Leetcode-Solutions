class Solution {
public:
    
    bool dfs(int i,int c, vector<int> &color, vector<vector<int>> &a) {
        color[i] = c;
        for(auto &node : a[i]) {
            if(color[node] == 0) {
                if(!dfs(node,3-c,color,a)) return false;
            }else if(color[node] == color[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> color(n,0);
        // 0 -> not visited, 1 -> Red color, and 2 -> blue color
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                flag = dfs(i,1,color,a);
            }
            if(!flag) return false;
        }
        return flag;
    }
};