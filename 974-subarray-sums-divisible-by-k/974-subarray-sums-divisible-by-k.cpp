class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        unordered_map<int,int> m;
        m[0]++;
        int ans = 0, sum = 0;
        for(auto &i : a) {
            sum += i;
            int r = sum%k;
            r = (r < 0) ? r + k : r;
            if(m.find(r) != m.end()) {
                ans += m[r];
            }
            m[r]++;
        }
        return ans;
    }
};