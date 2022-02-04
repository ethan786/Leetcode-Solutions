class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>s(n*2);
        for(int i=0;i<n;i++){
            s[i]=nums[i];
              s[n*2-(n-i)]=nums[i];
        }
        return s;
    }
};