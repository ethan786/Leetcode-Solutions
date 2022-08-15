class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size(), j = 0; 
        vector<pair<int,int>> p(n);
        for(auto &i : a) {
            p[j++] = {abs(i-x),i};
        }
        sort(p.begin(), p.end());
        vector<int> ans(k);
        j = 0;
        for(int i = 0; j < k; i++, j++) {
            ans[j] = p[i].second;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};