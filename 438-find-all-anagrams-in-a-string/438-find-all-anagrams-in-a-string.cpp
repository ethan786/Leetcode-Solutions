class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(n < m) return {};
        vector<int> fp(26,0), fs(26,0);
        for(auto &i : p) {
            fp[i-'a']++;
        }
        for(int i = 0; i < p.size(); i++) {
            fs[s[i]-'a']++;
        }
        
        int i = 0, j = m;
        
        vector<int> ans;
        
        if(fs == fp) ans.push_back(i);
        
        while(j < n) {
            fs[s[i++]-'a']--;
            fs[s[j++]-'a']++;
            if(fs == fp) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};