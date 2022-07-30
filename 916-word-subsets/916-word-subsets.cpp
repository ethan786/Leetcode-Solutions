class Solution {
public:
    
    void fill(vector<int> &freq, string &s) {
        for(auto &i : s) {
            freq[i-'a']++;
        }
    }
    
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> ans;
        vector<int> word(26,0);
        for(auto &i : b) {
            vector<int> freq(26,0);
            fill(freq, i);
            for(auto &j : i) {
                word[j-'a'] = max(word[j-'a'], freq[j-'a']);
            }
        }
        
        // for(auto &i : word) {
        //     cout<<i<<endl;
        // }
        
        for(auto &i : a) {
            vector<int> ma(26,0);
            for(auto &j : i) {
                ma[j-'a']++;
            }
            // is subset
            {
                bool ok = true;
                for(int j = 0; j < 26; j++) {
                    if(word[j] > ma[j]) {
                        ok = false;
                    }
                    if(!ok) break;
                }
                if(ok) ans.push_back(i);
            }
        }
        return ans;
    }
};