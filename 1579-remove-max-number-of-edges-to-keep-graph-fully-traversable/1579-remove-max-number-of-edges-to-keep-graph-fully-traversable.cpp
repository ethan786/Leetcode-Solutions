class dsu {
public:
    int *par;
    int *rank;
    int c;
    dsu(int n) {
        par = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 0; i < n + 1; i++) {
            par[i] = i;
            rank[i] = 1;
            c = 1;
        }
    }

    int find(int x) {
        return (x == par[x]) ? x : par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2) {
            if(rank[s1] > rank[s2]) {
                rank[s1] += rank[s2];
                par[s2] = s1;
            }else {
                rank[s2] += rank[s1];
                par[s1] = s2;
            }
            c++;
        }else{
            return false;
        }
        return true;
    }

};

class Solution {
public:
    
    int r = 0;
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& a) {
        sort(a.rbegin(), a.rend());
        
        dsu d1(n+1);
        dsu d2(n+1);
        for(int i = 0; i < a.size(); i++) {
            int x = a[i][1];
            int y = a[i][2];
            if(a[i][0] == 3) {
                bool p = d1.merge(x,y);
                bool q = d2.merge(x,y);
                if(!p || !q) r++;
            }else if(a[i][0] == 1) {
                if(!d1.merge(x,y)) {
                    r++;
                }
            }else{
                if(!d2.merge(x,y)) {
                    r++;
                }
            }
            
            // cout<<i<<endl;
            // for(int j = 1; j <= n; j++) {
            //     cout<<j<<" "<<d1.par[j]<<" "<<d2.par[j]<<endl;
            // }
            // cout<<d1.c<<" "<<d2.c<<" "<<r<<endl;
        }
        if(d1.c == n and d2.c == n) {
            // cout<<r;
            return r;
        }
        return -1;
    }
};