class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> s_map,t_map;
        int n = s.size(), m = t.size();
        for(auto &i : t) t_map[i]++;
        int matching = 0;
        int i = 0, j = 0, ans_len = INT_MAX, st;
        while(j < n) {
            s_map[s[j]]++;
            if(t_map.find(s[j]) != t_map.end() and s_map[s[j]] <= t_map[s[j]]) matching++;
            while(matching == m) {
                int cur_len = j-i+1;
                if(cur_len < ans_len) {
                    ans_len = cur_len;
                    st = i;
                }
                s_map[s[i]]--;
                if(s_map[s[i]] < t_map[s[i]]) matching--;
                i++;
            }
            j++;
        }
        if(ans_len == INT_MAX) return "";
        return s.substr(st,ans_len);
    }
};

// A D O B E C O D E B A  N  C
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// A-> 
// B->
// C->