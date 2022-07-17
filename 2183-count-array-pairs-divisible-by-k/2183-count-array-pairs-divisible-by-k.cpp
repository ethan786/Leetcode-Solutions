
class Solution {
public:
    long long countPairs(vector<int>& a, int k) {
        int n = a.size();
        
        vector<int> factor_k;
        for(int i = 1; i * i <= k; i++) {
            if(k % i == 0) factor_k.push_back(i);
            if((k/i) != i and k % i == 0) factor_k.push_back(k/i);
        }
        
        int64_t ans = 0;
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++) {
            ans += (m[k/__gcd(k,a[i])]);
            for(auto &j : factor_k) {
                if(a[i] % j == 0) m[j]++;
            }
        }
        
        return ans;
    }
};
