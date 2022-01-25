// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int c = 0;
//         int n = nums.size();
//         int ans = 0;
//         for(int i=1;i<n-1;i++){
//             int dif = nums[i] - nums[i-1];
//             //cout<<"dif- "<<dif<<" ";
//             if(dif == nums[i+1]-nums[i]){
//                 c++;
//             }else{
//                 int total_ele = c+2;
//                 if(total_ele >=3){
//                     cout<<total_ele;
//                     int x = total_ele - 2;
//                     ans += ((x+1)*x)/2;
//                 }
//                 c=0;
//             }
//         }
//         if(c!=0){
//              int total_ele = c+2;
//                 if(total_ele >=3){
//                     cout<<total_ele;
//                     int x = total_ele - 2;
//                     ans += ((x+1)*x)/2;
//                 }
//                 c=0;
//         }
//         return ans;
//     }
// };




































class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        
        int n=a.size();
        
        vector<int> v;
        int c=0;
        for(int i=1;i<n-1;i++)
        {
           int x=a[i]-a[i-1];
           if(a[i+1]-a[i]==x)
           {
               c++;
           }else{
               cout<<c;
                v.push_back(c+2);
                c=0;
            } 
        }
        int ans=0;
        if(c!=0){
            int a = c+2;
            if(a>=3)
          {
             int x=(a-2);
             ans+= (x*(x+1))/2;
          }  
        }
      for(auto i:v)
      {
          if(i>=3)
          {
             int x=(i-2);
             ans+= (x*(x+1))/2;
          }     
      }
        return ans;
    }
};