class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int ans = 0, n = a.size();
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,a[i]);
            if(mx == i){
                ans++;
                mx = INT_MIN;
            }
        }
        return ans;
    }
};
// 5 1 2 3 0 4 7 6