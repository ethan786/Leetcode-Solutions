class Solution {
public:
    int maxProduct(vector<string>& word) {
        // hashing the words using bit
        int n = word.size();
        vector<int> mask(n,0);
        {
            // hashing the word 
            for(int i = 0; i < n; i++) {
                for(auto &ch : word[i]) {
                    mask[i] |= 1 << (ch - 'a');
                }
            }
        }
        
        int ans = 0;
        
        {
            // now its become O(1) to check words have common element or not
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < i; j++) {
                    if((mask[i] & mask[j]) == 0) {
                        int x = word[i].size(), y = word[j].size();
                        ans = max(ans, x*y);
                    }
                }
            }
        }
        
        return ans;
        
    }

};

// "abcw"
// "baz"     "foo" "xtfn","
// "abcdef"
// "bar"