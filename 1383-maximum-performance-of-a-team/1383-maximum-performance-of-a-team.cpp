class Solution {
public:
    const int m = 1000000007;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> team; //for including k engineers team
        for(int i=0;i<n;i++){
            team.push_back({e[i],s[i]});
        }
        sort(team.rbegin(),team.rend());
        priority_queue<int,vector<int>,greater<int>> pq;//min heap for removing engineers with less                                                   //speed
        long sum = 0;
        long ans = 0;
        for(int i=0;i<n;i++){
            sum += team[i].second;
            pq.push(team[i].second);
            if(pq.size()>k){
                sum-=pq.top();//removing engineer with less speed
                pq.pop();
            }
            //long x = ((sum%m)*(team[i].first%m))%m;
                ans = max(ans,sum*team[i].first);
            
        }
        return ans%m;
    }
};
  
    