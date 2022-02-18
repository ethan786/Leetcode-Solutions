class Solution {
public:
    bool isPossible(string &st,vector<int> &v){
        vector<int> d = v;
        for(auto &c : st){
            if(d[c-'a'] == 0){
                return false;
            }else{
                d[c-'a']--;
            }
        }
        for(auto &c : st){
            if(v[c-'a'] > 0){
                v[c-'a']--;
            }
        }
        return true;
    }
    
    int sum(string &st,vector<int>& s){
        int ans = 0;
        for(auto &c : st){
            ans += s[c-'a'];
        }
        return ans;
    }
    
    void fillmap(string &st,vector<int> &v){
        for(auto &c : st){
            v[c-'a']++;
        }
        return;
    }
    
    int solve(int i,vector<string>& w, vector<int>& s,vector<int> &v){
        if(i == w.size()){
            return 0;
        }
        
        int op1= INT_MIN ,op2 = INT_MIN;
        op2 = solve(i+1,w,s,v);
        if(isPossible(w[i],v)){
            op1 = sum(w[i],s) + solve(i+1,w,s,v);
            fillmap(w[i],v);
        }
        return max({op1,op2});
    }
    
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        //sort(w.begin(),w.end());
        vector<int> v(26,0);
        for(int i=0;i<l.size();i++){
            v[l[i] - 'a']++;
        }
        return solve(0,w,s,v);
    }
};
//tanay = suar