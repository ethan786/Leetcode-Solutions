class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        
        vector<vector<int>> ans;
        int n = a.size();
        for(int bits = 0; bits < (1<<n); bits++) {
            vector<int> subset;
            for(int i = 0; i < n; ++i) {
                if(bits & (1 << i)) {
                    subset.push_back(a[i]);
                }
            }
            ans.push_back(subset);
        }
        
        return ans;
    }
};