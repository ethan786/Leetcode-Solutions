class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        set<int> s;
        for(auto &i : a) s.insert(i);
        for(auto &i : s) {
            if(s.find(i-1) == s.end()) {
                int num = i;
                int mx = 1;
                while(s.find(num+1) != s.end()) {
                    mx++;
                    num++;
                }
                ans = max(ans, mx);
            }
        }
        return ans;
    }
};