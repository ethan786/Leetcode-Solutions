class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        vector<int> odd;
        int n = a.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] & 1) odd.push_back(i);
        }
        unordered_map<int,int> m;
        int j = 0, oddEle = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2) oddEle++;
            // cout<<oddEle<<endl;
            while(j <= i and oddEle == k) {
                auto it = upper_bound(begin(odd), end(odd),i);
                if(it == odd.end()) {
                    ans += n-i;
                }else {
                    // cout<<*it<<" "<<i<<endl;
                    ans += *it-i; 
                }
                if(a[j] & 1) oddEle--;
                j++;
            }
        }
        return ans;
    }
};