class Solution {
public:
    
    vector<string> letterCombinations(string digits) { 
        int n=digits.size();
        if(n==0)return {};
        
        vector<string> digitString = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        ans.push_back("");
        
        for(int i=0;i<n;i++)
        {
            vector<string> temp;
            for(auto x: ans){
                for(auto y: digitString[(digits[i]-'0')]){
                    temp.push_back(x+y);
                }
            }
            ans=temp;
        }
        return ans;
    }
};