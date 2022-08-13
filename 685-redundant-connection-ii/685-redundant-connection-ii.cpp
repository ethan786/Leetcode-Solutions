// 3 cases
// 1) Two parents
// 2) cycle
// 3) Two parents with cycle
class Solution {
public:
    int *parent;
    int *rank;
    int find(int i) {
		if(parent[i] == i) {
			return i;
		}
		return parent[i] = find(parent[i]);
	}

	bool merge(int i, int j) {
		int s1 = find(i);
		int s2 = find(j);
		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
            return false;
		}else {
            return true;
        }
	}
    
    void fillDSU(int n) {
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i = 0 ; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        return;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> in(n+1,-1);
        int b1 = -1, b2;
        bool ok = false;
        // to check whether there is an edge which has 2 parent or not
        for(int i = 0; i < n; i++) {
            if(in[a[i][1]] != -1) {
                ok = true;
                b1 = i;
                b2 = in[a[i][1]];
                break;
            }
            in[a[i][1]] = i;
        }
        fillDSU(n);
        bool cycle = false;
        for(int i = 0; i < n; i++) {
            if(i == b1) continue;
            int u = a[i][0], v = a[i][1];
            bool is = merge(u,v);
            if(is) {
                if(b1 == -1) {
                    return a[i]; // case 2
                }else {
                    return a[b2]; // case 3
                }
            }
        }
        return a[b1]; // case 1
    }
};