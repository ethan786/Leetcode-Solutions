class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        int x = 0;
        for(auto &i : s) {
            x += (i - '0') * (i - '0');
        } 
        
        unordered_map<int,int> m;
        m[x]++;
        
        while(x != 1) {
            string y = to_string(x);
            x = 0;
            for(auto &i : y) {
                x += (i - '0') * (i - '0');
            } 
            if(m.find(x) != m.end()) return false;
            m[x]++;
        }
        return true;
    }
};