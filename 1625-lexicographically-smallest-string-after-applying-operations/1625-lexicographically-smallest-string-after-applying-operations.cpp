class Solution {
public:
    set<string> v;
    string add(string s,int a){
        string x;
        for(int i=0;i<s.size();i++){
            if(i%2 != 0){
                x += (((s[i] - '0') + a)%10 + '0');
                //cout<<x<<endl;
            }else{
                x += s[i];
                //cout<<x<<endl;
            }
        }
        return x;
    }
    
    string rotate(string s,int b){
        string x;
        int n = s.size();
        x += s.substr(n-b);
        x += s.substr(0,n-b);
        return x;
    }
    
    void solve(string s, int a, int b,string &ans){
        if(v.find(s) != v.end()) return;
        v.insert(s);
        ans = min(s,ans);
        solve(add(s,a),a,b,ans);
        solve(rotate(s,b),a,b,ans);
    }
    
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        solve(s,a,b,ans);
        return ans;
    }
};