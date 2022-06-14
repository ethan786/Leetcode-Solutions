class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        n = s.size();
        int x = n-1;
        for(; x > 0; x--) {
            int cur = s[x]-'0', prev = s[x-1]-'0';
            if(cur > prev) {
                break;
            }
        }
        if(x == 0) return -1;
        x--;
        int y = x+1, greater = s[x]-'0', ans = INT_MAX, ind = -1;
        while(y < n) {
            if(s[y]-'0' > greater) {
                ans = min(ans, s[y]-'0');
                ind = y;
            }
            y++;
        }
        char t = s[x];
        s[x] = s[ind];
        s[ind] = t;
        
        reverse(s.begin()+x+1, s.end());
        return stoll(s) > INT_MAX ? -1 : stoll(s);
    }
};
