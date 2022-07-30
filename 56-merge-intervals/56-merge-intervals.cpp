class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        pair<int,int> p = {a[0][0], a[0][1]};
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++) {
            if(p.second >= a[i][0]) {
                p.second = max(p.second, a[i][1]);
            }else {
                ans.push_back({p.first, p.second});
                p = {a[i][0], a[i][1]};
            }
        }
        ans.push_back({p.first, p.second});
        return ans;
    }
};