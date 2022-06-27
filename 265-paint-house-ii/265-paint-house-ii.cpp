class Solution {
public:
    int minCostII(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for(int i = 1; i < n; i++) {
            int first_min = INT_MAX, second_min = INT_MAX;
            for(int j = 0; j < m; j++) {
                first_min = min(a[i-1][j],first_min);
            }
            int x = first_min;
            for(int j = 0; j < m; j++) {
                if(x != a[i-1][j]) {
                    second_min = min(a[i-1][j],second_min);
                }else {
                    x = -5;
                }
            }
            // cout<<first_min<<" "<<second_min<<endl;
            for(int j = 0; j < m; j++) {
                if(first_min == a[i-1][j]) {
                    a[i][j] += second_min;
                }else {
                    a[i][j] += first_min;
                }
            }
        }
        return *min_element(a[n-1].begin(), a[n-1].end());
    }
};

// [3,20,7,7,16,8,7,12,11,19,1]
// [10,14,3,3,9,13,4,12,14,13,1]
// [10,1,14,11,1,16,2,7,16,7,19]
// [13,20,17,15,3,13,8,10,7,8,9]
// [4,14,18,15,11,9,19,3,15,12,15]
// [14,12,16,19,2,12,13,3,11,10,9]
// [18,12,10,16,19,9,18,4,14,2,4]