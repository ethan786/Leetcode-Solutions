class Solution {
public:
    
    int m = 1e9+7;
    
    int getNumberOfBacklogOrders(vector<vector<int>>& a) {
        priority_queue<pair<int,int>> buy, sell;
        for(int i = 0; i < a.size(); i++) {
            if(a[i][2] == 0)  {
                
                while(!sell.empty() and a[i][0] >= abs(sell.top().first) and a[i][1] > 0) {
                    auto order = sell.top();
                    sell.pop();

                    int S_price = abs(order.first);
                    int S_cap = abs(order.second);
                    int B_cap = a[i][1];
                    B_cap = (S_cap >= B_cap) ? 0 : B_cap - S_cap;
                    S_cap = (S_cap >= a[i][1]) ? S_cap - a[i][1] : 0;
                    // cout<<B_cap<<endl;
                    
                    if(S_cap != 0) {
                        sell.push({-S_price,S_cap});
                    }
                    
                    a[i][1] = B_cap;
                }
                // cout<<a[i][1]<<endl;
                if(a[i][1] != 0) {
                    // cout<<a[i][1]<<endl;
                    buy.push({a[i][0],a[i][1]});
                }
            }else {
                while(!buy.empty() and a[i][0] <= buy.top().first and a[i][1] > 0) {
                    auto order = buy.top();
                    buy.pop();
                    int B_price = order.first;
                    int B_cap = order.second;
                    int S_cap = a[i][1];
                    S_cap = (S_cap >= B_cap) ? S_cap - B_cap : 0;
                    B_cap = (a[i][1] >= B_cap) ? 0 : B_cap - a[i][1];
                    if(B_cap != 0) {
                        buy.push({B_price,B_cap});
                    }
                    a[i][1] = S_cap;
                }
                
                if(a[i][1] != 0) {
                    // cout<<a[i][1]<<endl;
                    sell.push({-a[i][0],a[i][1]});
                }
            }
        }
        // cout<<sell.top().first<<endl;
        long ans = 0;
        while(!buy.empty()) {
            // cout<<buy.top().second<<endl;
            ans += buy.top().second;
            ans %= m;
            buy.pop();
        }
        while(!sell.empty()) {
            // cout<<sell.top().second<<endl;
            ans += sell.top().second;
            ans %= m;
            sell.pop();
        }
        
        return ans%m;
    }
};