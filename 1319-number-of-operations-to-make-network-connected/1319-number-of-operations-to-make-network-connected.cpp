

class Solution {
public:
    //DSU
    
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
    
    // ans is to find the number of connected component 
    int makeConnected(int n, vector<vector<int>>& a) {
        if(a.size() < n-1) return -1; // it's not possible at all
        
        par = new int[n];
        rank = new int[n];
        //initialize the dsu
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = -1;
        }
        
        for(auto &i : a) {
            merge(i[0],i[1]);
        }
        
        int cc = 0;
        
        for(int i = 0; i < n; i++) {
            if(par[i] == i) cc++;
        }
        
        return cc - 1; // -1 for that connected component that is not solo
        
    }
};