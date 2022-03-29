class Solution {
public:
    bool checkVisited(vector<int>& visited)
{
    for (int i = 0; i < visited.size(); i++)
        if (!visited[i]) return false;
    return true;
}
vector<int> smallestRange(vector<vector<int>>& nums) {
    int minVal = INT_MAX, maxVal = INT_MIN, k = (int)nums.size();
    // visited: count the number of visited items to each list WITHIN CURRENT WINDOW, pointer: the pointer to each list when traversing
    // allNums: make all items in one list
    vector<int> visited(k, 0);
    vector<int> pointer(k, 0);
    vector<pair<int, int>> allNums;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<int> res = {-100000, 100000};
    // initialization
    for (int i = 0; i < k; i++)
    {
        if (nums[i].size())
        {
            que.push(make_pair(nums[i][0], i));
            pointer[i]++;
        }
    }
    // make allNums
    while(!que.empty())
    {
        pair<int, int> cur = que.top();
        que.pop();
        allNums.push_back(cur);
        if (pointer[cur.second] < nums[cur.second].size())  que.push(make_pair(nums[cur.second][pointer[cur.second]], cur.second));
        pointer[cur.second]++;
    }
    // traversing allNums to obtain res, using two-pointer technique
    minVal = allNums[0].first;
    maxVal = allNums[allNums.size() - 1].first;
    int left = 0;
    for (int i = 0; i < allNums.size(); i++)
    {
        visited[allNums[i].second]++;
        while (i < allNums.size() - 1 && allNums[i].first == allNums[i + 1].first)
        {
            i++;
            visited[allNums[i].second]++;
        }
        while (checkVisited(visited)) {
            if (allNums[i].first - allNums[left].first < res[1] - res[0] || (allNums[i].first - allNums[left].first == res[1] - res[0] && res[0] > allNums[left].first))
            {
                res[0] = allNums[left].first;
                res[1] = allNums[i].first;
            }
            while (left < allNums.size() - 1 && left <= i && allNums[left].first == allNums[left + 1].first)
            {
                visited[allNums[left].second]--;
                left++;
            }
            visited[allNums[left].second]--;
            left++;
        }
    }
    return res;
}
};