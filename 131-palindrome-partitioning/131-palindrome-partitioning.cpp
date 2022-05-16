class Solution {
public:
    
    bool isPalindrome(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int n;
    void solve(int i, string s,vector<string> &com, vector<vector<string>> &ans) {
        // base condition
        if(i == n){
            ans.push_back(com);
            return;
        }
        
        for(int j = i; j < s.size(); ++j){
            string x = s.substr(i,j-i+1);
            // cout<<x<<" "<<y<<endl;
            if(isPalindrome(x)){
                com.push_back(x);
                solve(j+1,s,com,ans);
                com.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> com;
        vector<vector<string>> ans;
        solve(0,s,com,ans);
        return ans;
    }
};

