class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        if(n < 2) return false;
        int preSum = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i = 0; i < n; i++) {
            preSum += a[i];
            if(m.find(preSum%k) != m.end()) {
              if(i - m[preSum%k] > 1) return true;  
            } else m[preSum%k] = i;
        }
        return false;
    }
};