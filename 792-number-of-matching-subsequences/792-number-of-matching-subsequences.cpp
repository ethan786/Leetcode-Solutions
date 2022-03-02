class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        map<char,vector<int>> m;
        for(int i=0;i<n;i++){
            m[s[i]].push_back(i);
        }
        int ans = 0;
        bool flag = true;
        for(auto &i : words){
            flag = true;
            string cur = i;
            int latest = -1;
            for(auto &j : cur){
                auto it = upper_bound(m[j].begin(),m[j].end(),latest);
                if(it == m[j].end()){
                    flag = false;
                    break;
                }
                latest = *it;
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};