class Solution {
public:
    int subarraySum(vector<int>& n, int k) {
        int r = 0, s = 0; unordered_map<int, int> m; 
        m[0]++;
        for (int i = 0; i < n.size(); i++) {
            s += n[i]; if (m[s - k]) r += m[s - k]; m[s]++;
        }
        return r;
    }
};