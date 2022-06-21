class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(a.size() == 0) return 0;
        unordered_set<int> s;
        for(auto &i : a) {
            s.insert(i);
        }
        
        int ans = 1;
        
        for(auto &i : a) {
            int c = 0;
            int num = i;
            if(!s.count(num-1)){
                while(s.count(num)) {
                    num++;c++;
                }
            }
            ans = max(ans, c);
        }
        return ans;
    }
};