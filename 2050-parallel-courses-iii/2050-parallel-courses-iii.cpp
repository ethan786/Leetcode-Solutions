template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '['<<p.first<<"," <<p.second<<"]" : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "["; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << "]\n"; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cout << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H; dbg_out(T...); }
 
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:\n", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time){
        
        vector<int> indegree(n+1,0), cost(n+1,0);
        vector<vector<int>> graph(n+1);
    
        for(int i=0;i<relations.size();i++){
            int u = relations[i][0], v = relations[i][1];
            indegree[v]++;
            graph[u].push_back(v);
        }
                
        queue<int> q;
        for(int node=1;node<=n;node++){
            if( indegree[node] == 0){                
                cost[node] = time[node-1];
                q.push(node);
            }
        }
                
        int ans = 0;
        while(!q.empty()){
            int node = q.front();
            int c = cost[node];
            q.pop();
                        
            ans = max(ans, c);
            
            for(auto &ngh:graph[node]){
                indegree[ngh]--;
                cost[ngh] = max(cost[ngh], cost[node]+time[ngh-1]);
                if(indegree[ngh] == 0)
                    q.push(ngh);
            }
        }
        return ans;
    }
};