class Solution
{
public:
    int ans = 0;
    int removeCoveredIntervals(vector<vector<int>> &a)
    {
        sort(a.begin(), a.end());
        int start = -1, end = -1;
        for (auto i : a)
        {
            if (start < i[0] && end < i[1])
            {
                start = i[0];
                end = i[1];
                ans++;
            }
            else
            {
                end = max(end, i[1]);
            }
        }
        return ans;
    }
};