class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        unordered_map<int,int> m;
        int n = a.size(), sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            sum += a[i];
            if(sum == x) {
                ans = min(ans, i+1);
            }
            m[sum] = i+1;
        }
        sum = 0;
        for(int i = n-1; i > -1; --i) {
            sum += a[i];
            if(sum == x) {
                ans = min(ans, n - i);
            }
            int f = x - sum;
            auto it = m.find(f);
            if(it != m.end()) {
                int ind = it->second;
                if(ind < i) {
                    ans = min(ans, ind+n-i);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};
