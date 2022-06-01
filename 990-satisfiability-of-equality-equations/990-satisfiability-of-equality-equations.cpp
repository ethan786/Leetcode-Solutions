class Solution {
public:
    
    char *par;
    
    int find(char i) {
        return (i == par[i]) ? i : par[i] = find(par[i]);
    }
    
    void merge(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        
        if(s1 != s2) {
            par[s1] = s2;
        }
    }
    
    bool equationsPossible(vector<string>& a) {
        par = new char[256];
        for(int i = 0; i < 256; i++) {
            par[i] = i;
        }
        
        for(auto &i : a) {
            if(i[1] == '=') {
                merge(i[0],i[3]);
            }
        }
        
        for(auto &i : a) {
            if(i[1] == '!') {
                if(find(i[3]) == find(i[0])) {
                    return false;
                }
            }
        }
        return true;
    }
};