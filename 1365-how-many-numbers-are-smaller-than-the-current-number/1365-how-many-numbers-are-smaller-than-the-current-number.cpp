// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<pair<int,int>> p;
//         int n = nums.size();
//         for(int i= 0; i<n;i++){
//             p.push_back({nums[i],i});
//         }
//         sort(p.begin(),p.end());
//         vector<int> v(n);
//         for(int i = 0;i<n;i++){
//             auto j = p[i];
//             if(p.first )
//             v[j.second] = i; 
//         }
//         return v;
//     }
// };    
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
    
        map<int,int> mp;    
        int n=nums.size();
        vector<int> snum=nums;
        
        sort(snum.begin(),snum.end());
        for(int i=n-1;i>=0;i--)
            mp[snum[i]]=i;
        
        for(int i=0;i<n;i++)
            nums[i]=mp[nums[i]];
        
        return nums;
    }
};