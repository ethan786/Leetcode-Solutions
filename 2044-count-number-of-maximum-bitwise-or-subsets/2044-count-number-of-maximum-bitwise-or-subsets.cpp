class Solution {
public:
    int mx;
    int solve(int i, vector<int> &a, int mx_or) {
        if(i == a.size()) {
            if(mx_or == mx) return 1;
            return 0;
        }
        int op1 = solve(i+1,a,mx_or | a[i]);
        int op2 = solve(i+1,a,mx_or);
        return op1 + op2;
    }
    
    int countMaxOrSubsets(vector<int>& a) {
        mx = 0;
        for(auto &i : a) mx = mx | i;
        return solve(0,a,0);
    }
};