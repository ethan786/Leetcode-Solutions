class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int preSum = 0, ans = 0;
        unordered_map<int,int> m;
        m[0]++;
        for(int i = 0; i < a.size(); i++) {
            preSum += a[i];
            if(m.find(preSum-k) != m.end()) ans += m[preSum-k];
            m[preSum]++;
        }
        return ans;
    }
};