class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& a) {
        int n = a.size(), max_reach = s, i = 0, ans = 0;
        priority_queue<int> pq;
        while(max_reach < t) {
            while(i < n and max_reach >= a[i][0]) {
                pq.push(a[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            max_reach += pq.top(), pq.pop();
            ans++;
        }
        return ans;
    }
};