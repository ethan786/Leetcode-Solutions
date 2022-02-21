class Solution {
public:
    int majorityElement(vector<int>& a) {
        int me = a[0];
        int c = 1;
        for(int i=1;i<a.size();i++){
            if(me == a[i]){
                c++;
            }else{
                c--;
                if(c==0){
                    me = a[i];
                    c = 1;
                }
            }
        }
        return me;
    }
};