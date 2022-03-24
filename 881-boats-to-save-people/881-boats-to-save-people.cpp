class Solution {
public:
    int numRescueBoats(vector<int>& a, int l) {
        int n = a.size();
        sort(a.begin(),a.end());
        int i = 0, j = n-1;
        int ans = 0;
        while(i<=j){
            if(i == j){
                ans++;
                return ans;
            }
            if(a[i] + a[j] <= l){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};