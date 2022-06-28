class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size(), ans = 1;
        vector<int> temp;
        temp.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if(temp.back() < a[i]) {
                temp.push_back(a[i]);
                ans++;
            }else {
                int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
                temp[ind] = a[i]; // replacing
            }
        }
        return ans;
    }
};