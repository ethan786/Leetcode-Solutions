class Solution {
public:
    // time taken - 3:48
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size(), i = 0, j = 0, ans = -1, sum = 0;
        unordered_map<int,int> m;
        while(j < n) {
            sum += a[j];
            m[a[j]]++;
            auto it = m.find(a[i]);
            if(it != m.end()) {
                while(m[a[j]] != 1) {
                    sum -= a[i];
                    m[a[i]]--;
                    if(m[a[i]] == 0) m.erase(a[i]);
                    i++;
                }
            }
            j++;
            ans = max(ans, sum);
        }
        return ans;
    }
};