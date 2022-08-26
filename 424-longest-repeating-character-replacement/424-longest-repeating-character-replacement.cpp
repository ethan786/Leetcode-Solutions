class Solution {
public:
    
    int possible(vector<int> &f) {
        int mx = 0, sum = 0;
        for(auto &i : f) {
            mx = max(i, mx);
            sum += i;
        }
        // cout<<sum - mx<<endl;
        return sum - mx;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> f(26,0);
        int j = 0, ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            // cout<<i<<" "<<ans<<endl;
            f[s[i] - 'A']++;
            while(possible(f) > k) {
                f[s[j] - 'A']--;
                j++;
                // cout<<i<<" "<<j<<endl;
            }
            ans = max(i-j+1, ans);
        }
        return ans;
    }
};