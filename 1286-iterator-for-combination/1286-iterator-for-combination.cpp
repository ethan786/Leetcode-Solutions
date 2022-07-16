class CombinationIterator {
public:
    set<string> s;
    
    void solve(int i, string &c, int len, string &ans) {
        if(i == c.size()) {
            if(ans.size() == len)
                s.insert(ans);
            return;
        }
        ans += c[i];
        solve(i+1,c,len,ans);
        ans.pop_back();
        solve(i+1,c,len,ans);
    }
    
    CombinationIterator(string c, int len) {
        string ans = "";
        solve(0,c,len,ans);
    }
    
    string next() {
        auto it = *s.begin();
        s.erase(s.begin());
        return it;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */