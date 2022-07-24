class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        int i = 0, j = m-1;
        while(i < n and j >= 0) {
            if(a[i][j] == k) return true;
            else if(a[i][j] > k) j--;
            else i++;
        }
        return false;
    }
};