class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    
    void solve(int i, string &s, vector<string> &p) {
        if(i == s.size()) {
            ans.push_back(p);
        }
        
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i,j,s)) {
                p.push_back(s.substr(i,j-i+1));
                solve(j+1,s,p);
                p.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> p;
        solve(0,s,p);
        return ans;
    }
};
