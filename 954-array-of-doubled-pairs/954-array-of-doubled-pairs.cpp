class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        unordered_map<int,int> m;
        for(auto &i : a){
            m[i]++;
        }
        int c = 0;
        int n = a.size();
        sort(a.rbegin(),a.rend());
        for(int i=0;i<n;i++){
            auto it = m.find(2*a[i]);
            if(a[i] == 0 and m[a[i]] > 1){
                c++;
                m[a[i]]--;
                m[a[i]]--;
                //cout<<a[i];
            }else if(a[i] != 0 and it != m.end() and it->second > 0 and m[a[i]] > 0){
                //cout<<it->first<<endl;
                c++;
                it->second--;
                m[a[i]]--;
            }
        }
        //cout<<c;
        return c == n/2;
    }
};