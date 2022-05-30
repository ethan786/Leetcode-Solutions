class Solution {
public:
    
    int *par;
    int *rank;
    
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    
    bool merge(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2) {
            if(rank[s1] > rank[s2]) {
                par[s2] = s1;
                rank[s1] += rank[s2];
            }else {
                par[s1] = s2;
                rank[s2] += rank[s1];
            }
        }else {
            return true;
        }
        return false;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        int n = a.size();
        par = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++) {
            par[i] = i;
            rank[i] = 1;
        }
        
        for(int i=0;i<n;i++) {
            if(merge(a[i][0]-1,a[i][1]-1)) {
                return {a[i][0],a[i][1]};
            }
        }
        return {};
    }
};