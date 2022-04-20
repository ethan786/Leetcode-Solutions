class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0; // For index of str1 (or subsequence
    for (int i = 0; i < t.size() && j < s.size(); i++){
        if (s[j] == t[i]){
            j++;
        }
    }
    return (j == s.size());
    }
};
