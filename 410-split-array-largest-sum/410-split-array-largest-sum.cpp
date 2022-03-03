class Solution {
public:
    
    bool isPossible(int mid,vector<int>& a,int m){
        int currSum = 0;
        int count = 1;
        int n = a.size();
        for(int i=0;i<n;i++){
            currSum += a[i];
            if(currSum > mid){
                currSum = a[i];
                count++;
                if(count > m){
                    return false;
                }
            } 
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
        
        int left = maxElement,right = sum;
        
        //binarySearch
        while(left <= right){
            int mid = left + (right-left)/2;
            if(isPossible(mid,a,m)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};
