class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int mx = -1;
        for(auto i : a){
            int sum = 0;
            for(auto j : i){
                sum += j;
            }
            mx = max(mx,sum);
        }
        return mx;
    }
};