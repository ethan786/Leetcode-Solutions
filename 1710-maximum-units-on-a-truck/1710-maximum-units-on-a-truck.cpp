class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int t) {
        sort(a.begin(),a.end(),[&](vector<int> &x, vector<int> &y) {
           return x[1] > y[1]; 
        });
        int ans = 0;
        for(auto &i : a) {
            if(t >= i[0]) {
                ans += i[0] * i[1];
                t -= i[0];
            }else {
                ans += t * i[1];
                return ans;
            }
        }
        return ans;
    }
};




    
    
    