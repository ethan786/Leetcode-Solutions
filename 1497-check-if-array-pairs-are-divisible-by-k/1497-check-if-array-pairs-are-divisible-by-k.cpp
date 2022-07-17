class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        unordered_map<int,int> m;
        for(auto &i : a) m[((i%k)+k)%k]++;
        for(auto &i : m) {
            if(i.first == 0) {
                if(i.second & 1) return false;
            }else {
                int f1 = i.first;
                int f2 = abs(f1-k);
                if(f1 == f2) {
                    if(m[f1] & 1) return false;
                }else {
                    if(m.find(f2) == m.end()) {
                        return false;
                    }else if(m[f2] != m[f1]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};