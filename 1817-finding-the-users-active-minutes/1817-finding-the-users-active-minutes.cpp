class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& l, int k) {
    
        unordered_map<int, unordered_set<int>>m;
        vector<int> ans(k);
        
        for(int i=0; i<l.size(); i++)
            m[l[i][0]].insert(l[i][1]);
        
        for(auto x: m)
            ans[x.second.size()-1]++;
        
        return ans;
    }
};