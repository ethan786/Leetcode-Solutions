class Solution {
public:
    
    bool isPossible(int mid,vector<int>& a,int m){
        int sum = 0;
        int count = 1;
        int n = a.size();
        for(int i=0;i<n;i++){
            sum += a[i];
            if(sum > mid){
                sum = a[i];
                count++;
            if(count > m){
                return false;
            }
            }
            //cout<<sum<<" "<<count<<" "<<mid<<endl;
        }
        return true;
    }
    
    int splitArray(vector<int>& a, int m) {
        int sum = 0;
        int maxElement = -1;
        for(auto &i : a){
            sum += i;
            maxElement = max(maxElement,i);
        }
        int l = maxElement,r = sum;
        //binarySearch
        while(l <= r){ // = case?
            int mid = l + (r-l)/2;
            if(isPossible(mid,a,m)){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
//42 10
//22