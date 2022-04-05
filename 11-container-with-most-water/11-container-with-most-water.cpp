class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = INT_MIN;
        int l = 0, r = a.size()-1;
        while(l<r){
            int area = (min(a[l],a[r]) * (r-l));
            ans = max(ans,area);
            if(a[l] < a[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};