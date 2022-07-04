class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> LeftToRight(n,1), RightToLeft(n,1);
        
        // Solution is that we distribute candies first 
        // taking left neighour in consideration and 
        // taking right neighour in consideration
        
        //left to right
        
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i-1]) {
                LeftToRight[i] = 1 + LeftToRight[i-1];
            }
        }
        
        // Right to left
        int ans = LeftToRight[n-1]; // max of left to right , right to left
        for(int i = n-2; i >= 0; i--) {
            if(a[i] > a[i+1]) {
                RightToLeft[i] = 1 + RightToLeft[i+1];
            }
            ans += max(RightToLeft[i],LeftToRight[i]);
        }

        return ans;
    }
};