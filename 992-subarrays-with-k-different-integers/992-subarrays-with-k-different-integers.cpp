class Solution {
public:
    
    int count(vector<int>& a, int k) {
        int ans = 0, n = a.size(), i = 0, j = 0;
        unordered_map<int,int> m;
        
        while(j < n) {
            m[a[j]]++;
            while(m.size() > k) {
                m[a[i]]--;
                if(m[a[i]] == 0) m.erase(a[i]);
                i++;
            }
            j++;
            ans += j-i+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return count(a,k) - count(a,k-1);
    }
};
            
// 1 2 3 1 2 3 2 4
// 0 1 2 3 4 5 6 7
// where it become exactly k (ki - maxki + 1)
//     6-2+1 = 4 + 4 + 3 + 3 + 1 + 2