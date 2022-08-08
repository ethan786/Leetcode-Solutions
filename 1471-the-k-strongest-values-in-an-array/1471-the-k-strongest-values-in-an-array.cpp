class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        int n = arr.size(), m = (n-1) / 2;
        int median = arr[m];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto &i : arr) {
            int diff = abs(i - median);
            if(pq.size() == k) {
                auto top = pq.top();
                int strength = top.first, val = top.second;
                if(strength < diff) {
                    pq.pop();
                    pq.push({diff, i});
                }else if(strength == diff and i > val) {
                    pq.pop();
                    pq.push({diff, i});
                }
            }else {
                pq.push({diff,i});
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};