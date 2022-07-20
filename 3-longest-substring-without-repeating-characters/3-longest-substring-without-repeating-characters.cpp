class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0, n = s.size(), ans = 0;
        unordered_map<char,int> m;
        for(int i = 0 ; i < n; i++) {
            m[s[i]]++;
            while(!m.empty() and m[s[i]] > 1) {
                m[s[j]]--;
                if(m[s[j]] == 0) m.erase(m.find(s[j]));
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};