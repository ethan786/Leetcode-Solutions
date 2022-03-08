class Solution
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>>hashes;   
        for(int j=0;j<strs.size();j++)
        {
            string hash=strs[j];
            sort(hash.begin(),hash.end());
            hashes[hash].push_back(strs[j]);
        }
        
        vector<vector<string>>ans;
        for(auto p:hashes)
            ans.push_back(p.second);
        
        return ans;
    }
};
