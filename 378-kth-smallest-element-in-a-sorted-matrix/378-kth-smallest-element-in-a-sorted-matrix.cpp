class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        priority_queue<int> p;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(p.size() == k){
                    if(a[i][j] < p.top()){
                        p.pop();
                        p.push(a[i][j]);
                    }
                }else{
                    p.push(a[i][j]);
                }
            }
        }
        return p.top();
    }
};