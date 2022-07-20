class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        map<char,vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[s[i]].push_back(i);
        }
        
        int ans = 0;
        
        for(string &i : words) {
            string cur = i;
            int latest = -1;
            bool flag = true;
            for(char &j : i) {
                auto it = upper_bound(m[j].begin(), m[j].end(), latest);
                if(it == m[j].end()) {
                    flag = false;
                }
                if(!flag) break;
                latest = *it;
            }
            if(flag) ans++;
        }
        return ans;
    }
};

// aaaaaaaa.....b
// aaaab

// we are doing so much of time in finding b
// instead of finding b we can store the position of b