class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int mx = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            nums[i] == 0 ? sum -= 1 : sum += 1;
            if(sum == 0){
                mx = max(mx,i+1);
            }
            if(m.find(sum) != m.end()){
                mx = max(i-m[sum] , mx);
            }else{
                m[sum] = i;
            }
        }
        return mx;
    }
};