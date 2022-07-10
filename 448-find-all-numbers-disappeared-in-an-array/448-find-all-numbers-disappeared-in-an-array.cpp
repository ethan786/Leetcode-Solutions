class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        vector<int> ans;
        int c = 1;
        sort(a.begin(), a.end());
        for(int i = 0 ;i < a.size(); i++) {
            // cout<<c<<" "<<a[i]<<endl;
            if(c == a[i]) {
                c++;
            }else if(c < a[i]) {
                ans.push_back(c);
                c++;
                i--;
            }
        }
        while(c < a.size()+1) {
            ans.push_back(c++);
        }
        return ans;
    }
};

// 1 2 2 3 3 4 7 8
// c = 5