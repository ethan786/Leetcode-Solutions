class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        
        sort(begin(a), end(a));
        vector<vector<int>> ans;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int64_t sum = t;
                sum -= a[i]; // we need to find sum using 2 pointer
                sum -= a[j];
                int left = j+1, right = n-1;
                while(left < right) {
                    int64_t l_r = a[left] + a[right];
                    if(l_r < sum) left++;
                    else if(l_r > sum) right--;
                    else {
                        ans.push_back({a[i],a[j],a[left],a[right]});
                        int l = a[left], r = a[right];
                        while(left < right and a[left] == l) left++;
                        while(left < right and a[right] == r) right--;
                    }
                }   
                while(j+1 < n and a[j+1] == a[j]) j++;
            }
            while(i+1 < n and a[i+1] == a[i]) i++;
        }
        return ans;
    }
};