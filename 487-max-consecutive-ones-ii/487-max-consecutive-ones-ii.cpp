class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size();
        int j = 0;
        int c = 0;
        int ans = 0;
        for(int i = 0; i< n; i++) {
            if(a[i] == 0) {
                c++;
                if(c > 1) {
                    while(c > 1) {
                        if(a[j] == 0) c--;
                        j++;
                    }
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};