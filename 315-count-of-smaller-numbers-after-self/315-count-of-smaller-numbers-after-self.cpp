#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& a) {
        pbds pd;
        int n = a.size();
        vector<int> ans(n,0);
        for(int i = n-1; i >= 0; i--) {
            pd.insert(a[i]);
            ans[i] = pd.order_of_key(a[i]); 
        }
        return ans;
    }
};