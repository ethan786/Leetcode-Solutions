class Solution {
public:
    int minEatingSpeed(vector<int>& p, int m) {
        int n = p.size();
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,p[i]);
        }
        int l = 1,h=mx;
        int ans = INT_MAX;
        while(l<h){
            int mid = (l+h)/2;
            int hours=0;
            for(int i : p){
                hours += i/mid + (i%mid!=0);
            }
         if(hours <= m){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return h;
    }
};
 