class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int buy = a[0];
        for(int i = 1; i < a.size(); i++) {
            if(buy > a[i]) {
                buy = a[i];
            }else {
                ans = max(a[i] - buy, ans);
            }
        }
        return max(ans,0);
    }
};