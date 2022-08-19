class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        for(int bit = 0; bit < 1 << n; bit++) {
            vector<int> subsets;
            for(int i = 0; i < 32; i++) {
                if((1 << i) & bit) subsets.push_back(a[i]);
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};