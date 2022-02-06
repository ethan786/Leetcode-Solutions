class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<pair<int,int>> p;
        int n = g.size();
        for(int i=0;i<n;i++){
            p.push_back({g[i],i});
        }
        sort(p.begin(),p.end());
        vector<vector<int>> v;
        int i=0;
        while(i<n){
            vector<int> t;
            int s = p[i].first;
            while(s--){
                t.push_back(p[i].second);
                i++;
            }
            v.push_back(t);
        }
        return v;
    }
};