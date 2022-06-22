class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        priority_queue<int> pq;
        int n = a.size();
        int i = 0;
        for(i = 0; i < n-1; i++) {
            if(a[i+1] - a[i] > 0) {
                int diff = a[i+1] - a[i];
                b -= diff;
                pq.push(diff);
                if(b < 0 and l) {
                    int top = pq.top();
                    pq.pop();
                    l--;
                    b += top;
                }else if(b < 0 and !l) break;
            }
        }
        return i;
    }
};