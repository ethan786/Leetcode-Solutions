class Solution {
public:
    const int mod = 1e9+7;
    int uniqueLetterString(string a) {
        int n = a.size();
        vector<int> left(n,-1), right(n,-1);
        vector<int> lastl(26,-1), lastr(26,n);
        for(int i = 0; i < n; i++) {
            left[i] = i - lastl[a[i]-'A'];
            lastl[a[i]-'A'] = i;
        }
        for(int i = n-1; i >= 0; i--) {
            right[i] = lastr[a[i]-'A'] - i;
            lastr[a[i]-'A'] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + (abs(left[i]) * abs(right[i]) % mod)) % mod;
            // cout<<left[i]<<" "<<right[i]<<endl;
        }
        return ans;
    }
};