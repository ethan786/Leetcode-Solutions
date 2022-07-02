class Solution {
public:
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        #define int int64_t
        a.insert(begin(a),0);
        a.push_back(h);
        b.insert(begin(b),0);
        b.push_back(w);
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        int ma = -1, mb = -1;
        
        for(int i = 0; i < a.size()-1; i++) {
            ma = max(ma, (int) (a[i+1] - a[i]));
        }
        
        for(int i = 0; i < b.size()-1; i++) {
            mb = max(mb, (int)(b[i+1] - b[i]));
        }
        
        int ans = (ma * mb) % 1000000007;
        
        #undef int
        
        return ans;
        
    }
};