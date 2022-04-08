class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) {
        if(arr.size()==1){// for array with single element.
            return (arr[0]==t)?1:0;
        }
        
        int l=0,r=0,s=0,len=arr.size();
        while(r<arr.size()){
            s+=arr[r];// add new element to sum  
            while(l<=r && s>=t){ // took l<=r to check if single element is >= target ,this loop should run
                len=min(len,(r-l+1));
                s-=arr[l];// remove left pointer from sum
                l++; // increase left pointer as new array starts from next index 
            }
            r++;
        }
        if(!l && s<t){ // for array whose total sum is less than target , left pointer is at 0th index and sum is less than target
            return 0;
        }
        return len;
    }
};