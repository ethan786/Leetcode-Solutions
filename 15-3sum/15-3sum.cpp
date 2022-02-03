class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        if(n.size()<=2){
            //cout<<"scas";
            return {};
        }else if(n.size() == 3){
           if(n[0]+n[1]+n[2] == 0){
                return {{n[0],n[1],n[2]}};
           }else{
               return {};
           }
        }
        vector<vector<int>> ans;
        sort(n.begin(),n.end());
        for(int i=0;i<n.size()-2;i++){
            if(i==0 || (i > 0 and n[i] != n[i-1])){
            int l = i+1,h=n.size()-1;
            int newTarget = -1*n[i];
            while(l<h){
                int sum = n[l] + n[h];
                if(newTarget == sum){
                    ans.push_back({n[l],n[h],-1*newTarget});
                    while(l < h and n[l] == n[l+1]){
                        l++;
                    }
                    while(l < h and n[h] == n[h-1]){
                        h--;
                    }
                    l++;
                    h--;
                }else if(sum > newTarget){
                    h--;
                }else{
                    l++;
                }
            }
            }else{
                continue;
            }
        }
        return ans;
    }
};