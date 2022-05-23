class Solution {
public:
    
    int *par;
    int *rank;
    
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    
    void merge(int x, int y) {
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
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        par = new int[n];
        rank = new int[n];
        //initialize the dsu
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = -1;
        }
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i+1; j < a.size(); ++j) {
                if(a[i][j] == 1) {
                    merge(i,j);
                }
            }
        }
        
        int cc = 0;
        
        for(int i = 0; i < n; i++) {
            if(par[i] == i) cc++;
        }
        return cc;
    }
};
