class Solution {
public:
    int minimumLengthEncoding(vector<string>& s) {
        unordered_map<string,int> m;
        for(auto &i : s) {
            m[i]++;
        }
        for(auto &i : s) {
            for(int j = 1; j < i.size(); j++) {
                string x = i.substr(j,i.size()-j);
                if(m.find(x) != m.end()) {
                    m[x]--;
                    if(m[x] == 0) m.erase(x);
                }
            }
        }
        int ans = 0;
        for(auto &i : m) {
            ans += i.first.size() + 1;
        }
        return ans;
    }
};