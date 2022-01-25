class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        if(a.size()<3){
            return 0;
        }
        int c=0;
        
        for(int i=1;i<a.size()-1;i++){
            if(a[i-1]==a[i] || a[i]==a[i+1]){
                return 0;
            } 
            if(a[i-1]>a[i] && a[i]<a[i+1]){
                return 0;
            }
            if(a[i-1]<a[i] && a[i]>a[i+1]){
                c++;
            }
        }
        return c==1;
    }
};