class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int> e;
        vector<int> o;
        for(int &i : a){
            if(i%2 == 0){
                e.push_back(i);
            }else{
                o.push_back(i);
            }
        }
        vector<int> ans;
        for(int &i : e){
            ans.push_back(i);
        }
        for(int &i : o){
            ans.push_back(i);
        }
        return ans;
        
    }
};