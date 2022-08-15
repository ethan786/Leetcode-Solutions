class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        auto solve = [&](int i, int sum) {
            int l = i, r = n-1;
            while(l <= r) {
                int m = (l + r) / 2;
                if(a[m] >= sum) {
                    r = m - 1;
                }else {
                    l = m + 1;
                }
            }
            return l;
        };
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n-1; j++) {
                int sum = a[i] + a[j];
                // no of smaller element than sum in the array
                ans += solve(j+1, sum) - j - 1;
            }
        }
        return ans;
    }
};

// 2 2 3 4 