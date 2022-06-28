class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();
        // vector<int> temp;
        // temp.push_back(a[0]);
        // int ans = 1;
        // for(int i = 1; i < n; i++) {
        //     if(temp.back() < a[i]) {
        //         temp.push_back(a[i]);
        //         ans++;
        //     }else {
        //         int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
        //         temp[ind] = a[i];
        //     }
        // }
        // return ans >= 3;
        int x = INT_MAX, y = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(a[i] <= x) {
                x = a[i];
            }else if(a[i] <= y) {
                y = a[i];
            }else {
                return true;
            }
        }
        return false;
    }
};