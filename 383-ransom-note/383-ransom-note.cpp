class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int,int> m;
        for(auto &i : magazine) m[i]++;
        for(auto &i : ransomNote) {
            if(m.find(i) == m.end()) return false;
            m[i]--;
            if(m[i] == 0) m.erase(i);
        }
        return true;
    }
};