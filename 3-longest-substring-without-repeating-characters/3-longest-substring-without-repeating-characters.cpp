class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , n = s.size(), j = 0, ans = 0;
        unordered_map<char,int> m;
        // m[s[i]]++;
        while(j < n) {
            auto it = m.find(s[j]);
            m[s[j]]++;
            if(it != m.end()) {
                while(m[s[j]] != 1) {
                    m[s[i]]--;
                    if(m[s[i]] == 0) m.erase(s[i]);
                    i++;
                }
            }
            j++;
            ans = max(ans,(int)m.size());
        }
        return max(ans,(int)m.size());
    }
};