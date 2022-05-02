class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();
    
    int maxMin = INT_MIN;
    for (int i = 0; i < m; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
            min = std::min(min, mat[i][j]);
        maxMin = std::max(maxMin, min);
    }

    int minMax = INT_MAX;
    for (int j = 0; j < n; j++) {
        int max = INT_MIN;
        for (int i = 0; i < m; i++)
            max = std::max(max, mat[i][j]);
        minMax = std::min(minMax, max);
    }
    
    if (maxMin != minMax) return vector<int> { };
    return vector<int> { maxMin };
    }
};