class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        map<int,int> m;
        for(auto &i : f) {
            m[i[0]]++; 
            m[i[1]+1]--;
        }
        vector<int> ans(p.size());
        int k = 0, pre = m[0];
        for(auto &i : m) {
            pre += i.second;
            i.second = pre;
        }
        for(auto &i : p) {
            auto it = m.upper_bound(i);
            if(it == m.begin()) {
                ans[k++] = 0;
            }else {
                ans[k++] = prev(it)->second;
            }
        }
        return ans;
    }
};

// 1  3  4  11
// 1  2  1  0  