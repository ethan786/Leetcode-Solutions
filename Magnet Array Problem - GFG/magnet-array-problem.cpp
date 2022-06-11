// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{

    public:
     void nullPoints(int n, double magnet[], double getAnswer[])
   {
       // Your code goes here   
       for(int i=1;i<n;i++){
           double low = magnet[i-1],high = magnet[i];
           bool fl = 1;
           while(low<=high){
               double mid = low + (high-low)/2;
               double right_force = 0,left_force = 0;
               
               for(int j=i;j<n;j++){
                   left_force += (1/(magnet[j]-mid));
               }
               for(int j=i-1;j>=0;j--){
                   right_force += (1/(mid-magnet[j]));
               }
               
               if(abs(right_force-left_force)<0.000001){
                   getAnswer[i-1] = mid;
                   fl = 0;
                   break;
               }
               else if(right_force>left_force){
                   low = mid;
               }
               else{
                   high = mid;
               }
           }
           
           if(fl){
               getAnswer[i-1] = low;
           }
           
       }
       
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends