class Solution {
public:
    bool CanWeTakeItOrNot(vector<vector<int>>& special, vector<int>& needs,int i){
        int n = needs.size();
        for(int j=0;j<n;j++){
            if(special[i][j] > needs[j]){
                return false;
            }
        }
        return true;
    }
    
    int solve(int i,vector<int>& p, vector<vector<int>>& special, vector<int> &needs){
        if(i==special.size()){
            int sum = 0;
            for(int i=0;i<p.size();i++){
              //cout<<p[i]<<" "<<needs[i]<<endl;
                sum += p[i] * needs[i];
            }
            //cout<<sum<<" ";
            return sum;
        }
        if(CanWeTakeItOrNot(special,needs,i)){
            for(int j=0;j<needs.size();j++){
                //cout<<needs[j]<<" "<<special[i][j]<<endl;
                needs[j] = needs[j] - special[i][j];
               // cout<<needs[j]<<" ";
            }
            int op1 = special[i][special[0].size()-1] + solve(i,p,special,needs);
            for(int j=0;j<needs.size();j++){
                needs[j] += special[i][j];
            }
            int op2 = solve(i+1,p,special,needs);
            //cout<<op1<<" "<<op2<<endl;
            return min(op1,op2);
        }else{
            return solve(i+1,p,special,needs);
        }
    }
    
    int shoppingOffers(vector<int>& p, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0,p,special,needs);
    }
};