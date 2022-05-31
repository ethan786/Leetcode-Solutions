class Solution {
public:
    // simple we can extract all the substring of size k and store them and check whether the size of       // map is equal to 2^k
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        unordered_map<string,int> m;
        for(int i = 0; i < s.size() - k + 1; i++) {
            string x = s.substr(i,k);
            m[x]++;
        }
        // cout<<m.size();
        return m.size() == pow(2,k);
    }
};