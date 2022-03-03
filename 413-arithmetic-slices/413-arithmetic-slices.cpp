class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        //vector<int> d(n-1);
        int ans = 0;
        if(n >= 3){
            int d = a[1] - a[0];
            int c=1;
            for(int i=1;i<n-1;i++){
                if(d == a[i+1] - a[i]){
                    c++;
                }else{
                    if(c >= 2){
                        ans += ((c-1)*c)/2;
                    }
                    c = 1;
                    d = a[i+1] - a[i];
                }
            }
            if(c > 1){
                ans += ((c-1)*c)/2;
            }
            return ans;
        }else{
            return 0;
        }
        
    }
};