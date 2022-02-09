class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<0) return 0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto i : m){
            if(k==0){
                if(i.second>=2) ans++;
            }else{
                if(m.count(k+i.first)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
