class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto it = mp.begin();it!=mp.end();it++){
            p.push({it->second,it->first});
            if(p.size()>k){
                p.pop();
            }
        }
        vector<int> v;
        while(!p.empty()){
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};